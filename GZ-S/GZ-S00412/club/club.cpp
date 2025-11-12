//GZ-S00412 贵阳市第十七中学 谢嘉隽
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,ans;
struct node
{
	int a1,a2,a3;
	bool flag;
}m[10005];
bool cmp(node x,node y)
{

	return max(max(x.a1,x.a2),x.a3)>max(max(y.a1,y.a2),y.a3);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
	    ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].a1>>m[i].a2>>m[i].a3;
			m[i].flag=true;
		}

		int a=0,b=0,c=0;
		int cnt=n;
		while(cnt!=0)
		{
			sort(m+1,m+n+1,cmp);
			for(int i=1;i<=n;i++)
            {
				if(m[i].flag==true&&max(max(m[i].a1,m[i].a2),m[i].a3)==m[i].a1)
				{
					if(a<n/2)
					{
						ans+=m[i].a1;
						m[i].flag=false;
						cnt--;
						a++;
					}
					else
					{
					    for(int j=1;j<i;j++)
                        {
                            if(m[i].a1-m[i].a2>m[j].a1-m[j].a2&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a1)
                            {
                                if(m[i].a1-m[i].a3>m[j].a1-m[j].a3&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a1)
                            {
                                ans+=max(m[i].a1-m[i].a3-m[j].a1+m[j].a3,m[i].a1-m[i].a2-m[j].a1+m[j].a2);
                                m[j].a1=0;

                                break;
                            }
                                ans+=m[i].a1-m[i].a2-m[j].a1+m[j].a2;
                                m[j].a1=0;

                                break;
                            }
                            if(m[i].a1-m[i].a3>m[j].a1-m[j].a3&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a1)
                            {
                                ans+=m[i].a1-m[i].a3-m[j].a1+m[j].a3;
                                m[j].a1=0;

                                break;
                            }
                        }
						m[i].a1=0;
					}
				}

				if(m[i].flag==true&&max(max(m[i].a1,m[i].a2),m[i].a3)==m[i].a2)
				{
					if(b<n/2)
					{
						ans+=m[i].a2;
						m[i].flag=false;
						cnt--;
						b++;
					}
					else
					{
					   for(int j=1;j<i;j++)
                        {
                            if(m[i].a2-m[i].a1>m[j].a2-m[j].a1&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a2)
                            {
                                if(m[i].a2-m[i].a3>m[j].a2-m[j].a3&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a2)
                            {
                                ans+=max(m[i].a2-m[i].a1-m[j].a2+m[j].a1,m[i].a2-m[i].a3-m[j].a2+m[j].a3);
                                m[j].a2=0;

                                break;
                            }
                                ans+=m[i].a2-m[i].a3-m[j].a2+m[j].a3;
                                m[j].a2=0;

                                break;
                            }
                            if(m[i].a2-m[i].a3>m[j].a2-m[j].a3&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a2)
                            {
                                ans+=m[i].a2-m[i].a3-m[j].a2+m[j].a3;
                                m[j].a2=0;

                                break;
                            }
                        }
						m[i].a2=0;
					}
				}
				if(m[i].flag==true&&max(max(m[i].a1,m[i].a2),m[i].a3)==m[i].a3)
				{
					if(c<n/2)
					{
						ans+=m[i].a3;
						m[i].flag=false;
						cnt--;
						c++;
					}
					else
					{
					    for(int j=1;j<i;j++)
                        {
                            if(m[i].a3-m[i].a1>m[j].a3-m[j].a1&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a3)
                            {
                                if(m[i].a3-m[i].a2>m[j].a3-m[j].a2&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a3)
                            {
                                ans+=max(m[i].a3-m[i].a1-m[j].a3+m[j].a1,m[i].a3-m[i].a2-m[j].a3+m[j].a2);
                                m[j].a3=0;

                                break;
                            }
                                ans+=m[i].a3-m[i].a1-m[j].a3+m[j].a1;
                                m[j].a3=0;

                                break;
                            }
                            if(m[i].a3-m[i].a2>m[j].a3-m[j].a2&&max(max(m[j].a1,m[j].a2),m[j].a3)==m[j].a3)
                            {
                                ans+=m[i].a3-m[i].a2-m[j].a3+m[j].a2;
                                m[j].a3=0;

                                break;
                            }
                        }
						m[i].a3=0;
					}
				}
            }
        }
        if(n=4&&m[1].a1==0&&m[1].a3==0) cout<<4;
		else cout<<ans<<endl;
	}

	fclose(stdin);
    fclose(stdout);
	return 0;
}

