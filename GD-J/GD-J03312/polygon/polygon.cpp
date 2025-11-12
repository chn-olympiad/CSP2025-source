#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int N=5010;
int a[N],c[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=0;i<=N;i++){
		c[i][0]=0;
		c[i][i]=1;
		c[i][1]=i;
	}
	for(int i=2;i<=N;i++){
		for(int j=2;j<i;j++){
			c[i][j]=(long long)(c[i-1][j-1]+c[i-1][j])%Mod;
		}
	}
	int n;
	cin>>n;
	int maxn=0,ans=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3){
		if(n<3){
			cout<<0<<"\n";
			return 0;
		}
		else{
			if(sum>2*maxn){
				cout<<1<<"\n";
				return 0;
			}
		}
	}
	if(maxn<=1){
		for(int i=3;i<=n;i++){
			ans=(long long)(ans+c[n][i])%Mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
