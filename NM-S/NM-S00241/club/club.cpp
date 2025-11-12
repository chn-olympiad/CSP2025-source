#include<bits/stdc++.h>
using namespace std;
struct g{
    int z,r;
    char b;
};
int cmp(g x,g y)
{
    return x.z>y.z;
}
int t,n,b=0,c=0,ans=0;
g a[300010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
    {
        cin>>n;
        int k=1,i,j,x=0,y=0,z=0;
        bool h[100010];
        for(i=1;i<=n;i++)
        {
            h[i]=true;
            cin>>a[k].z>>a[k+1].z>>a[k+2].z;
            a[k].b='a';
            a[k+1].b='b';
            a[k+2].b='c';
            a[k].r=i;
            a[k+1].r=i;
            a[k+1].r=i;
            k+=3;
        }
        sort(a+1,a+1+n*3,cmp);
        for(i=1;i<=n*3;i++)
        {
            if(h[a[i].r]==true)
            {
                if(a[i].b=='a'&&x<n/2)
                {
                    x++;
                    ans+=a[i].z;
                }
                else if(a[i].b=='b'&&y<n/2)
                {
                    y++;
                    ans+=a[i].z;
                }
                else if(a[i].b=='c'&&z<n/2)
                {
                    z++;
                    ans+=a[i].z;
                }
                h[a[i].r]=false;
            }
        }
        cout<<ans<<endl;
        x=0;
        y=0;
        z=0;
        ans=0;
    }
    return 0;
}
