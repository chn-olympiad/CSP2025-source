#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		return 0;
	}
	int an=0;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			mx=a[i];
		}
		an+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(an>mx){
			ans++;
		}
	}
	cout<<ans; 
	return 0;
}
