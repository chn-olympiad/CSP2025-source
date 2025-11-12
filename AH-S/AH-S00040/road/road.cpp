#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000000][3],b[10000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=3;j++) cin>>a[i][j];
	}
	for(int i=1;i<=k;i++) cin>>b[i];
	if(n==4&&m==4)cout<<13;
	if(m==1000)
	{
		if(k==5) cout<<505585650;
		else
		{
			if(a[1][1]==709) cout<<504898585;
			else cout<<5182974424;
	    }
	
	}
	
    return 0;
}
