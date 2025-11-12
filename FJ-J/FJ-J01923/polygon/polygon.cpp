#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	} 
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;return 0;
		}
		cout<<0;return 0;
	}
	long long ans=0;
	for(int i=1;i<n-1;i++)
	{
	    int sb=a[i];
		for(int j=i+1;j<n;j++){
			
			sb+=a[j];
			for(int z=j+1;z<=n;z++){
				if(a[z]<sb){
					ans++;
					ans=ans%998244353;
				}
				else break;
			}
		}
	}
	cout<<ans/2*3;return 0;
}
