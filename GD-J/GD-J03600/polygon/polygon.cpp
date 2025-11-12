#include<bits/stdc++.h>
using namespace std;
#define int long long



const int N=998244353;
int n,a[5001],sum=0,maxn=0,res=0,flag=1;
int p[5001],cnt=1;


int A(int m,int n){
	int tmp1=1,tmp2=1;
	for(int i=1;i<=n;i++){
		tmp1=(tmp1*(m-i+1))%N;
	}
	for(int i=1;i<=n;i++){
		tmp2=(tmp2*i)%N;
	}
	return tmp1/tmp2;
}

void dfs(int i,int s){
	if(i>n){
		if(cnt<=3)return;
		else{
//			cout<<cnt<<"	";
			for(int j=1;j<cnt;j++){
//				cout<<p[j]<<' ';
				maxn=max(maxn,p[j]);
				sum+=p[j];
			}
//			cout<<'\n';
			if(sum>maxn*2){
				res=(res+1)%N;
			}
			maxn=0,sum=0;
			return;
		}
	}
	dfs(i+1,s);
	p[cnt++]=a[i];
	dfs(i+1,s);
	p[--cnt]=0;
}



signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(n<3)cout<<0<<'\n';
	else if(n==3){
		sum=a[1]+a[2]+a[3];
		maxn=max({a[1],a[2],a[3]});
		if(sum>maxn*2)cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	else if(flag&&n>20){
		for(int i=3;i<=n;i++){
			res=(res+A(n,i))%N;
		}
		cout<<res<<'\n';
	}
	else{
		dfs(1,0);
		cout<<res<<'\n';
	}
	return 0;
}
