#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,ans,a[N],b[N],c[N],d[4],x[N],y[N];
int main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(d,0,sizeof(d));
		cin>>n;
		for(int i=1;i<=n;i++)
		{	
			cin>>a[i]>>b[i]>>c[i];
			x[1]=a[i],x[2]=b[i],x[3]=c[i];
			y[a[i]]=1,y[b[i]]=2,y[c[i]]=3;
			sort(x+1,x+4);
		    if(d[y[x[3]]]<(n/2))
		    {
		    	ans+=x[3];
		    	d[y[x[3]]]++;
			}
			else if(d[y[x[2]]]<(n/2))
        	{
        		ans+=x[2];
        		d[y[x[2]]]++;
         	}
            else if(d[y[x[1]]]<(n/2))
         	{
     	        ans+=x[1];
            	d[y[x[1]]]++;
        	}
		}
		cout<<ans<<endl;
    }
	return 0;
}