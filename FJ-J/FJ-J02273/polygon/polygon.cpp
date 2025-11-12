#include<bits/stdc++.h>
using namespace std;
int n,s,mx,c,a[5130];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		mx=max(mx,a[i]);
	}
	if(n==3&&s>mx*2)cout<<1<<endl;
	else cout<<0<<endl;
}

