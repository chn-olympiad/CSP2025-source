#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool cmp(int x,int y)
{
	return x>y;
}
int l[100020][4];
int s[100020];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q=0;
	cin>>q;
	while(q--) 
	{
		int ans=-0x3f3f3f;
		int cnt=1;
		bool tag=0;
		int sum=0; 
		int cl1=0,cl2=0,cl3=0;
		
		int n=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>l[i][j];
				s[cnt]=l[i][j];
				cnt++;
			}
		}
	
		sort(s+1,s+n*3+1,cmp);
		
		//for(int i=1;i<=n*3;i++)
		//{
		//	cout<<s[i]<<endl;
		//}
		for(int p=1;p<=n*3;p++)
		{
			for(int i=p;i<=n*3;i++)
			{
				if(cl1+cl2+cl3==n)
				{
					break;
				}
				for(int j=1;j<=n;j++)
				{
					if(tag)
					{
						tag=0;
						break;
					}
					for(int z=1;z<=3;z++)
					{
						if(s[i]==l[j][z])
						{
							if(z==1)
							{
								if(cl1<n/2)
								{
									cl1++;
									l[j][1]=-1;
									l[j][2]=-1;
									l[j][3]=-1;
									sum+=s[i];
								}
							}
							if(z==2)
							{
								if(cl2<n/2)
								{
									cl2++;
									l[j][1]=-1;
									l[j][2]=-1;
									l[j][3]=-1;
									sum+=s[i];
								}
							}
							if(z==3)
							{
								if(cl3<n/2)
								{
									cl3++;
									l[j][1]=-1;
									l[j][2]=-1;
									l[j][3]=-1;
									sum+=s[i];
								}
							}
							tag=1;
							break;
						}
					}
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	  
	
	
	
}
