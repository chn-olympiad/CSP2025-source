#include<bits/stdc++.h>
using namespace std;
int a[5005];
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	for(int i=1;i<n-2;i++){
		int h=0,k=1;
		while(k<=n-2){
			for(int j=3;j<=n;j++){
				if(j-k+1>=3){
					h=a[i]+s[j]-s[k];
					if(h>(s[j]-s[j-1])*2) ans++;
				}
			}
			k++;
		}
		
	}
	cout<<ans%998244353;
	return 0;
}
