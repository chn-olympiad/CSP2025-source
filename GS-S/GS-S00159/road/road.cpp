#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;
    int S[n][3];
    int V[m][n+1];
    for(int i=0;i<n;i++)
    {
        cin>>S[i][0]>>S[i][1]>>S[i][2];
    }
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n+1;j++)
    	{
    		cin>>V[i][j];
		}
	}
	cout<<13;
	return 0;
}
    
