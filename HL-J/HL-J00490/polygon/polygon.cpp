#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ma=0,tot=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if(ma<a[i])ma=a[i];
		tot+=a[i];
	}
	int ans=0;
	if(tot>ma*2){
		ans++;
	}
	cout<<ans;
	return 0;
}
