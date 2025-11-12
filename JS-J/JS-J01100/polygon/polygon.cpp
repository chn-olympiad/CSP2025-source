#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<=(1<<n);i++){
		int res=0;
		int d=i;
		int maxi=-INT_MAX;
		for(int j=1;d>0;j++){
			bool t=d-d/2*2;
			d/=2;
			if(t==1){
				maxi=max(maxi,a[j]);
				res+=a[j];
			}
		}
		if(res>2*maxi){
			ans++;
		}
	}
	cout<<ans-ans/998224353*998224353;
	return 0;
}
