#include<bits/stdc++.h>
using namespace std;
int n,t;
int b[100010][5];
int ans,mx;
struct x
{
	int a,b,c,tmp1,tmp2,max;
}s[100010];
bool cmp(x a,x b)
{
	if(a.max>b.max)
		return true;
	else return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;long long sum=0,ans=-1;
		int a=n,b=0,c=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			sum+=s[i].a;
			s[i].tmp1=s[i].b-s[i].a;
			s[i].tmp2=s[i].c-s[i].a;
			s[i].max=max(s[i].tmp1,s[i].tmp2);
		}
		sort(s+1,s+n+1,cmp); 
		for(int j=1;j<=n;j++)
		{
			if(a>0)
			{
				a--;
//				if(s[j].max==s[j].tmp1&&s[j].max==s[j].tmp2&&(b<n/2||c<n/2))
//				{
//					if(b<c&&b<n/2)
//					{
//						b++;sum+=s[j].tmp1;
//						ans=max(ans,sum);
//						b--;sum-=s[j].tmp1;
//					}
//					else if(c<n/2)
//					{
//					
//						c++;sum+=s[j].tmp2;
//							ans=max(ans,sum);
//						c--;sum-=s[j].tmp2;
//					}
//					
//				}
//				else 
				if(s[j].max==s[j].tmp1&&b<n/2)
				{
					b++;
					sum+=s[j].tmp1;
				}
				else if(s[j].max==s[j].tmp2&&c<n/2)
				{
					c++;
					sum+=s[j].tmp2; 
				}
			//	sum=sum-s[j].a;
				//cout<<sum<<' '<<'b'<<b<<' '<<'c'<<c<<' ';
				//cout<<n/2;
				ans=max(ans,sum);
			}
		}
		cout<<ans<<'\n';
	}

 } 
