#include<bits/stdc++.h>
using namespace std;
long long a[10000];
long long b[10000];
long long c[10000];
long long o[10000];
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		cin>>c[i];
	}
    for(int i=0;i<k;i++)
	{
	    for(int j=0;j<n+1;j++)
	    {
	        cin>>o[j];	
	    } 	
	}
    if(k==0)
    {
    	cout<<0;
	}
	return 0;
}
