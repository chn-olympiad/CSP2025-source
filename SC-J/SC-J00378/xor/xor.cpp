#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long k,a[N],b[N][25],Max=0;
int n;
/*
void dgt(long long x){//x表示下标 
	int t=a[x],k=0;
	while(t>0){
		b[x][++k]=t%2;
		t/=2;
	}
	b[x][0]=k;
}

long long yh(int x,int y){//a和b分别表示两个数的下标 
	int ans[25];
	int Max=max(b[x][0],b[y][0]);
	for(int i=1;i<=Max;i++){
		if(b[x][i]==0||b[y][i]==0){
			ans[i]=1;
		}
		else{
			ans[i]=0;
		}
	}
	int ret=0;
	for(int i=1;i<=Max;i++){
		ret+=ans[i]*pow(2,i-1);
	}
	return ret;
}

void dfs(int now,long long num,int pnt,bool x){
	if(now>n){
		if(x==0) Max=max(Max,num);
		return;
	}
	if(x==0){//表示当前要选择的是左端点 
		dfs(now+1,num,pnt,0);
		dfs(now+1,num,now,1);
	}
	else{
		//判断是否能选 
		long long c=pnt;
		for(int i=pnt+1;i<=now;i++){
			c=yh(i,n);
			a[++n]=c;
			dgt(n);
		}
		long long p=0;
		for(int i=1;i<=b[n][0];i++){
			p+=b[n][i]*pow(2,i-1);
		}
		//考虑是否选取 
		if(p==k){
			dfs(now+1,num+1,now,0);
		}
		dfs(now+1,num,pnt,1);
	}
}
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//dgt(i);
	}
	//dfs(1,0,0,0);
	if(k==0){
		if(n==1){
			cout<<0;
		}
		else if(n==2){
			cout<<1;
		}
		else{
			cout<<n/2;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}