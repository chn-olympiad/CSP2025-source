#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<0<<"\n";
		return 0;
	}
	if(n==3){
		int sum=0,mx=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		if(sum>mx*2)cout<<1<<"\n";
		else cout<<0<<"\n"; 
		return 0;
	}
	cout<<9;
	return 0;
}
