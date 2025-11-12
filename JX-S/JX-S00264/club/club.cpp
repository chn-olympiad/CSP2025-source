#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=1e5+24;
int n;
int a[N][5];
int now[N],c[N];
int ch[N];
int nx(int x){return (x==3)?1:(x+1);}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ll ans=0;
        c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2])
			{
				if(a[i][1]>a[i][3])now[i]=1,c[1]++,ans+=a[i][1];
                else now[i]=3,c[3]++,ans+=a[i][3];
			}
            else
            {
                if(a[i][2]>a[i][3])now[i]=2,c[2]++,ans+=a[i][2];
                else now[i]=3,c[3]++,ans+=a[i][3];
            }
		}
        int d=0,tt=0;
		for(int i=1;i<=3;i++)
        {
			//cout<<c[i]<<"\n";
            if(c[i]>n/2)
            {
                d=c[i]-(n/2);
                for(int j=1;j<=n;j++)
                {
                    if(now[j]==i)
                    {
                        ch[++tt]=min(a[j][i]-a[j][nx(i)],a[j][i]-a[j][nx(nx(i))]);
                    }
                }
            }
        }
        //cout<<d<<" ";
        if(d!=0)
        {
            sort(ch+1,ch+tt+1);
            for(int i=1;i<=d;i++)ans-=ch[i];
        }
        cout<<ans<<"\n";
	}
	return 0;
}
