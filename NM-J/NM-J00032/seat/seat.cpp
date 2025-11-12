#include<bits/stdc++.h>
using namespace std;
long long cj[110];
int c,r;
int R=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>cj[i];
	    cj[0]=R;
		for(int j=1;j<=m;j++)
		{
			if(cj[i]>cj[j]) {
				             r=r+1;
				             cout<<c<<r;
				             continue;
		                	}    
		}
	}
	fclose(stdin);
	fclose(stdout);
    return 0;	
}
