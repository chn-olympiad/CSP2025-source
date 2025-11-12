#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        int p[100010][4],q[100010][4],r[100010][3],n,k[4]={0,0,0,0},sum=0,s,x[4]={0,1,1,-1},y[4]={0,2,-1,-2},m=INT_MAX,m1,l;;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i][1]>>p[i][2]>>p[i][3];
            if(p[i][1]>=p[i][2]&&p[i][1]>=p[i][3])
            {
                k[1]++;
                q[k[1]][1]=i;
            }
            else if(p[i][2]>=p[i][1]&&p[i][2]>=p[i][3])
            {
                k[2]++;
                q[k[2]][2]=i;
            }
            else if(p[i][3]>=p[i][1]&&p[i][3]>=p[i][2])
            {
                k[3]++;
                q[k[3]][3]=i;
            }
        }
        for(int i=1;i<=3;i++)
        {
        	if(k[i]>n/2)
        	{
				s=i;
			}
		}

		for(int i=1;i<=k[s];i++)
		{
			if(p[q[i][s]][s+x[s]]>=p[q[i][s]][s+y[s]])
			{
				r[i][1]=p[q[i][s]][s]-p[q[i][s]][s+x[s]];
				r[i][2]=s+x[s];
			}
			else
			{
				r[i][1]=p[q[i][s]][s]-p[q[i][s]][s+y[s]];
				r[i][2]=s+y[s];
			}
		}
		int o=k[s];
		while(o>n/2)
		{
			for(int i=1;i<=k[s];i++)
			{
				if(m>r[i][1])
				{
					m=r[i][1];
					m1=i;
				}
			}
			r[m1][1]=INT_MAX;
			q[k[r[m1][2]]+1][r[m1][2]]=q[m1][s];
			q[m1][s]=0;
			k[r[m1][2]]++;
			o--;
			m=INT_MAX;
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				sum+=p[q[j][i]][i];
			}
		}
		cout<<sum<<endl;
    }
    return 0;
}
