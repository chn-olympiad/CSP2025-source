#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)cout<<1;
	else cout<<0;
	return 0;
}