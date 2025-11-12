#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
double x=1;
int a[5005];
int maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxn) cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			x=1;
			for(int j=1;j<=i;j++){
				x=x*(n-j+1);
				x/=i-j+1;
			}
			ans=(ans+int(x))%998244353;
		}
		cout<<ans;	
	}
	
	
	return 0;
}
