#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int l,r;
}res[2000010];

int n,kk,m;
int a[500010];
int tot[22][500010];
int sum1[22],sum2[22];
int ans;
int k[22];
bool flag=1;

void ten_two(int num,int id){
	int cnt=0;
	while(num>0){
		tot[++cnt][id] = num%2;
		num/=2;
	}
	return;
}

void qzh(int y){
	for(int i=1;i<=20;i++){
		if(tot[i][y]==tot[i][y-1])tot[i][y] = 0;
		else tot[i][y] = 1;
	}
	return ;
}

void com(int xx){
	for(int i=1;i<=20;i++){
		if(tot[i][xx]==k[i])sum1[i] = 0;
		else sum1[i] = 1;
	}
	return ;
}

bool check(int id){
	for(int k=1;k<=20;k++){
		if(sum1[k]!=tot[k][id]){
			return 0;
		}				
	}
	return 1;
}

bool cmp(node xx,node yy){
	if(xx.r!=yy.r)return xx.r<yy.r;
	return xx.l>yy.l;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&kk);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1)flag=0; 
	} 
	//----------------------------输入 
	if(kk==1&&flag){ //B中1 
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		printf("%d",ans);
		return 0; 
	}
	if(kk==0&&flag){ //A,B中0 
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i-1]==1)ans++,a[i]=0;
		}
		printf("%d",ans);
		return 0;
	}
	//----------------------------特判
	 
	while(kk>0){ 
		k[++k[0]] = kk%2;
		kk/=2;
	}
	for(int i=1;i<=n;i++)ten_two(a[i],i); 
	//-----------------------------二进制化
	
	for(int i=2;i<=n;i++)qzh(i);
	//-----------------------------前缀和 
	
	for(int i=1;i<=n;i++){
		com(i);
		for(int j=i;j>=1;j--){
			if(check(j-1)){
				++m;
				res[m].l=j;
				res[m].r=i; 
			}
		}
	}
	//-----------------------------寻找有哪些区间 
	sort(res+1,res+m+1,cmp);
	int ls = 0;
	int ac = 0;
	for(int i=1;i<=m;i++){
		if(ls<res[i].l)ac++,ls=res[i].r;
	}
	printf("%d",ac);
	return 0;
}