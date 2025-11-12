#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+5;
int a[N][3];
int go[N];
int dp[N];//共3部门共j个人的满意最大值
int t,n;
int b1size;
int b2size;
int b3size;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			go[i] = 0;
			dp[i] = 0;
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		b1size=0;
		b2size=0;
		b3size=0;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
			
		for(int j=1;j<=n;j++)
		{
			int i1=0,i2=0,i3=0,g1=0,g2=0,g3=0;
			if(b1size == n/2)
			{
				g1 = N;
				int minh=0;
				for(int k=1;k<=n;k++)
				{
					if(go[k] == 1 && g1 > min(a[k][1]-a[k][2],a[k][1]-a[k][3]))
					{
						minh = k;
						g1 = min(a[k][1]-a[k][2],a[k][1]-a[k][3]);
					}
				}
				
				i1 = minh;
			} 
			if(b2size == n/2)
			{
				g2=N;
				int minh=N;
				for(int k=1;k<=n;k++)
				{
					if(go[k] == 2 && g2 > min(a[k][2]-a[k][1],a[k][2]-a[k][3]))
					{
						minh = k;
						g2 = min(a[k][2]-a[k][1],a[k][2]-a[k][3]);
					}
				}
				
				i2 = minh;
			} 
			if(b3size == n/2)
			{
				g3=N;
				int minh=N;
				for(int k=1;k<=n;k++)
				{
					if(go[k] == 3 && g3 > min(a[k][3]-a[k][2],a[k][3]-a[k][1]))
					{
						minh = k;
						g3 = min(a[k][3]-a[k][2],a[k][3]-a[k][1]);
					}
				}
				
				i3 = minh;
			}
			
			if(a[j][1]+g1 >= a[j][2]+g2 && a[j][1]+g1 >= a[j][3]+g2)
			{
				if(b1size == n/2)
				{
					dp[j] = max(dp[j],dp[j-1] + a[j][1] - a[i1][1]);
					go[j] = 1;
					int e1=a[i1][1],e2=a[i1][2],e3=a[i1][3];
					if(e2 > e3) go[i1] = 2;
					else go[i1] = 3;
					dp[j] += a[i1][go[i1]];
					b1size--;
				}
				else
				{
					dp[j] = max(dp[j],dp[j-1] + a[j][1]);
					go[j] = 1;
				}
				b1size++;
			}
			
			else if(a[j][2]+g2 >= a[j][1]-g1 && a[j][2]+g2 >= a[j][3]+g3)
			{
				if(b2size == n/2)
				{
					dp[j] = max(dp[j],dp[j-1] + a[j][2] - a[i2][2]);
					go[j] = 2;
					int e1=a[i2][1],e2=a[i2][2],e3=a[i2][3];
					if(e1 > e3) go[i2] = 1;
					else go[i2] = 3;
					dp[j] += a[i2][go[i2]];
					b2size--;
				}
				else
				{
					dp[j] = max(dp[j],dp[j-1] + a[j][2]);
					go[j] = 2;
				}
				b2size++;
			}
			else
			{
				if(b3size == n/2)
				{
					dp[j] = max(dp[j],dp[j-1] + a[j][3] - a[i3][3]);
					go[j] = 3;
					int e1=a[i3][1],e2=a[i3][2],e3=a[i3][3];
					if(e1 > e2) go[i3] = 1;
					else go[i3] = 2;
					dp[j] += a[i3][go[i3]];
					b3size--;
				}
				else
				{
					dp[j] = max(dp[j],dp[j-1] + a[j][3]);
					go[j] = 3;
				}
				b3size++;
			}
		}
		cout<<dp[n]<<endl;
	}
	
	return 0;
}
