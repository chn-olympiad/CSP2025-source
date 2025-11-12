#include<bits/stdc++.h>
using namespace std;
struct node{
    int p;
    int f;
};
node a[100005],b[100005],c[100005];
int d[100005],e[100005][3];
bool s[100005];
bool cmp(node a,node b)
{
    return a.p>b.p;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
        {
        	int x,y,z;
			cin>>x>>y>>z;
			a[i].p=x,b[i].p=y,c[i].p=z;
			a[i].f=i,b[i].f=i,c[i].f=i;
			e[i][0]=x,e[i][1]=y,e[i][2]=z;
			if(x<y) swap(x,y);
			if(x<z) swap(x,z);
			if(y<z) swap(y,z);
			d[i]=x-y;
        }
        sort(a,a+n,cmp),sort(b,b+n,cmp),sort(c,c+n,cmp);
		int cnt1=0,cnt2=0,cnt3=0,cnt=0;
		memset(s,0,sizeof(s));
			long long sum=0;
			int ai=0,bi=0,ci=0,k1[100000],k2[100000],k3[100000];
			while(cnt!=n)
            {
                if(ai<n&&cnt1+1<=n/2&&a[ai].p>=b[bi].p&&a[ai].p>=c[ci].p)
                {
                    if(!s[a[ai].f])
                    {
                        s[a[ai].f]=1;
                        sum+=a[ai].p;
                        cnt++;
                        k1[cnt1++]=d[a[ai].f];
                    }
                    else ai++;
                }
                else if(bi<n&&cnt2+1<=n/2&&b[bi].p>=c[ci].p)
                {
                    if(!s[b[bi].f])
                    {
                        s[b[bi].f]=1;
                        sum+=b[bi].p;
                        cnt++;
                        k2[cnt2++]=d[b[bi].f];
                    }
                    else bi++;
                }
                else
                {
                    if(ci<n&&cnt3+1<=n/2&&!s[c[ci].f])
                    {
                        s[c[ci].f]=1;
                        sum+=c[ci].p;
                        cnt++;
                        k3[cnt3++]=d[c[ci].f];
                    }
                    else ci++;
                }
                if(cnt1==n/2||cnt2==n/2||cnt3==n/2) break;
            }
            sort(k1,k1+n/2),sort(k2,k2+n/2),sort(k3,k3+n/2);
            int flag;
            if(cnt1==n/2) flag=0;
            if(cnt2==n/2) flag=1;
            if(cnt3==n/2) flag=2;
            int test=0;
            for(int i=0;i<n;i++)
            {
            	if(s[i]) continue;
            	if(flag==0&&k1[test]<e[i][0]-max(e[i][1],e[i][2]))
            	{
            		sum+=e[i][0]-k1[test++];
				}
				else if(flag==1&&k2[test]<e[i][1]-max(e[i][0],e[i][2]))
            	{
            		sum+=e[i][1]-k2[test++];
				}
				else if(flag==2&&k3[test]<e[i][2]-max(e[i][0],e[i][1]))
            	{
            		sum+=e[i][2]-k3[test++];
				}
				else
				{
					if(flag==0)
						sum+=max(e[i][1],e[i][2]);
					if(flag==1)
						sum+=max(e[i][0],e[i][2]);
					if(flag==2)
						sum+=max(e[i][0],e[i][1]);
				}
			}
            cout<<sum<<'\n';
	}
	return 0;
}
