#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int m=1;m<=n;m++){
			if(a[i]+a[j]+a[m]>=sum&&i!=j&&i!=m&&j!=m){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
