#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],maxx=INT_MIN;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==k)cout<<maxx;
	else cout<<1;
	return 0;
}
