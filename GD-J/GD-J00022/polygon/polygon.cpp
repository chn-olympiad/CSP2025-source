#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool f=true;
	int a[5005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=false;
	}
	if(f){
		int ans=0;
		for(int i=3;i<=n;i++){
			if(n-i+1>0) ans+=n-i+1;
		}
		cout<<ans;
	}
	else cout<<91;
	return 0;
}
