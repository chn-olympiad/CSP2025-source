#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxx=0;
	int s=0;
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		ans+=a[i];
		if (maxx==max(a[i],maxx))
		{
			continue;
		}
		maxx=max(a[i],maxx);
		s=i;
	}
	
	if (ans>=2*a[s])
	{
		cout<<1;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
