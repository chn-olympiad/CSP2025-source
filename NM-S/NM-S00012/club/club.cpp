#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int q,w,e;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++)
    {
		cin>>n;
		int x,y,z;
		int max=0;
		for(int j=0;j<n;j++)
		{
			cin>>x>>y>>z;
			if(x>y && x>z)
			{
				max+=x;
		    }
		    else if(y>x && y>z)
			{
				max+=y;
		    }
		    else
		    {
				max+=z;
			}
		}
		ans[i]=max;
    }
    for(int i=0;i<t;i++)
	{
		cout<<ans[i]<<endl;
	} 
    return 0;
}
