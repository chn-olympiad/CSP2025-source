#include <bits/stdc++.h>
using namespace std;
int n[5005];
int s[5005];
bool shiyong[5005];
int zuida;
int r;
long long ans;
long long linshi;

bool cmp(int x,int y)
{
	if (x<y) return true;
	else
	{
		return false;
	}
}

void pailie(int t,int l)//生成排列方式 
{
	for (int i=1;i<=r;i++)//给当前位数取数 
	{
		if (i<=zuida)
		{
			continue;
		}
		else
		{
			zuida=i;
		}
		if (shiyong[i]==false)
		{
			shiyong[i]=true;
			s[t]=n[i];
			if (t==l)
			{
				/*for (int k=1;k<=l;k++)
				{
					cout<<s[k]<<' ';
				}
				cout<<endl;*/
				//这一段用来输出所有排列 
				for (int k=1;k<=l;k++)
				{
					linshi+=s[k];
				}
				if (linshi>n[zuida]*2)
				{
					ans++;
				}
				linshi=0;
			}
			else
			{
				pailie(t+1,l);
			}
			s[t]=0;
			shiyong[i]=false;
			zuida=i;
		}
	}
}


int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>r;
	for (int i=1;i<=r;i++)
	{
		cin>>n[i];
	}
	
	sort(n+1,n+1+r,cmp);
	
	for (int i=3;i<=r;i++)
	{
		pailie(1,i);
		zuida=0;
	}
	cout<<ans%998244353;
	return 0;
}
