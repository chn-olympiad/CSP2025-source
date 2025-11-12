#include <bits/stdc++.h> 
using namespace std;

const int maxn=1e5+5;
struct ss
{
	int x,y;
}; 
bool cmp(ss s1,ss s2)
{
	return s1.x<s2.x;
}

ss a[maxn][3],b[3],c[maxn];
int n,t;
long long ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
    while (t--)
    {
    	memset(a,0,sizeof(a));
    	map <int ,int> mp;
    	ans=0;
    	cin>>n;
	    for (int i=1;i<=n;i++)
	    {
           cin>>b[0].x>>b[1].x>>b[2].x;
           b[0].y=0;
           b[1].y=1;
           b[2].y=2;
           sort(b,b+3,cmp);
           for (int j=0;j<=2;j++)a[i][j]=b[j];
	    }
	    for (int i=1;i<=n;i++)
        {
		   c[i].x=a[i][2].x-a[i][1].x;
		   c[i].y=i;
	    }
	    sort(c+1,c+n+1,cmp);
	
	    for (int i=n;i>=1;i--)
	    {
		   if (mp[a[c[i].y][2].y]<n/2)
		   {
		 	   ans+=a[c[i].y][2].x;
		 	   mp[a[c[i].y][2].y]++;
		   }
		   else
		   {
			   ans+=a[c[i].y][1].x;
			   mp[a[c[i].y][1].y]++;
		   }
     	}
     	cout<<ans<<"\n";
	}
	return 0;
}
