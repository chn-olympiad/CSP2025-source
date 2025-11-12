#include<bits/stdc++.h>
using namespace std;
const long long MOD= 998244353;
long long  cnt;
int ans[500005];//被挑出来的 
int n,book[5005];
int a[5005];//原来的 
int check(int k){ //检查是否能围成多边形 
	int sum=0;
	for(int i=1;i<=k;i++){
		sum+=ans[i];
	}
	if(sum>(2*a[k])) return 1;
	else return 0;
}
int t; //当前被挑出来的数字的个数 
void dfs(int k,int pos){ //挑 
	if(t==k) {
		if(check(k)){
			cnt++;
			cnt%=MOD;
		}
		return ;
	}
	if(pos>n) return ;
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			 ans[++t]=a[i];
			 book[i]=1;
			 dfs(k,pos+1);
			 book[i]=0;
			 t--;
		}	
	}
}

int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	scanf("%d",&n) ;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	long long ANS=0;
	for(int i=3;i<=n;i++){
		dfs(i,1);
//		cout<<cnt<<" ";
	}
	cout<<cnt<<endl;
	return 0;
}
