#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum,maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(sum>maxx*2)cout<<1;	
	else cout<<0;
	return 0;
}
