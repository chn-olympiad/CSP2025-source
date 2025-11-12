#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mx=-1,c=0;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		c+=a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(c>mx*2){
			cout<<1;
		}
		else
		cout<<0;
	}else{
		cout<<n+1;
	}
	return 0;
}
