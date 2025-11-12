#include<bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int main()
{
    int n,m,b[100],s=0,p=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    s=b[1];
    sort(b+1,b+1+n*m);
    for(int i=m*n;i>=1;i--)
    {
		if(b[i]==s)
		p=m*n-i;
		break;
	}
    if(p%m!=0)
    {
	    cout<<p/m+1<<" ";
	    if((p/m+1)%2==1)
	    {   
		    cout<<p%m;
	    }
	    else
	    cout<<m-p%m;
	}
	else
	{
	    cout<<p/m<<" ";
	    if((p/m)%2==1)
	    {
		    cout<<p%m;
	    }
	    else
	    cout<<m-p%m;
	}

    return 0;
}
