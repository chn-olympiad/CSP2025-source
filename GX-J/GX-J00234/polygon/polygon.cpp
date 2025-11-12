#include  <bits/stdc++.h>
using namespace std;

int n,a[5005];
long long jia[5005];
long long ans;

int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
		
	int q;	
	for(int j=1;j<n;j++){
		for(int i=j;i<n;i++){
		if(a[i]>a[i+1]){
			q=a[i];
			a[i]=a[i+1];
			a[i+1]=q;
			}
		}
		}
	
	for(int i=1;i<=n;i++){
		jia[i]=jia[i-1]+a[i];
		}
	
	for(int i=1;i<=n-3;i++){
		for(int j=i+3;j<=n-3;j++){
			if(jia[j]-jia[i-1]>a[j]*2)ans++;
			
			}
		
		
		}
	
	cout<<ans%998244353;
	return 0;
	}
	
