#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int32_t main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int sum=0,ma=-1;
			for(int k=i;k<=j;k++){
				sum+=a[k];
				ma=max(a[k],ma);
			}
			if(sum>=ma*2) ans++;
		}
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4

