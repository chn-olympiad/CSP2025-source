#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
long long shu[5050][5050];
long long mo=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(n<3){
			cout<<0;
			return 0;
		}
		int t=0;
		for(int i=1;i<=n;i++){
			t+=a[i];
		}
		if(t>a[n]*2) cout<<1;
		else cout<<0;
	}
	else if(a[n]==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==1) shu[i][j]=j;
				else if(j==1) shu[i][j]=1;
				else if(j==2) shu[i][j]=shu[i-1][j]+1;
				else shu[i][j]=(shu[i][j-1]+shu[i-1][j])%mo;
				shu[i][j]=shu[i][j]%mo;
			}
		}
		long long res=0;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				res+=shu[i-1][j];
				res=res%mo;
				//cout<<shu[i-1][j];
			}
		}
		cout<<res%mo;
	}
	return 0;
} 