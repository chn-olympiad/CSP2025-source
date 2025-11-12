#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005],b,x,ans;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	cin>>b>>x>>a[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<m;i++)
	{
	    ans+=a[i];
	}
	cout<<ans;
	return 0;
}
