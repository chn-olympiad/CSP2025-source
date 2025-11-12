#include <iostream>
#include <string>
using namespace std;

int cmpin(string a,string b)
{
	int j=0,ans=0;
	for(int i=0;i<b.size();++i)
	{
		if(j==a.size()) return ans-j+1;
		if(b[i]==a[j])
		{
			ans=i;
			++j;
		}
		else if(b[i]!=a[j]&&j!=0)
		{
			j==0;
		}
	}
	if(j==a.size()) return ans-j+1;
	return -1;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string a[n+1][2];
	for(int i=1;i<=n;++i)
	{
		cin >> a[i][0] >> a[i][1]; 
	}
	for(int i=1;i<=q;++i)
	{
		string b[2];
		cin >> b[0] >> b[1];
		int ans=0;
		for(int j=1;j<=n;++j)
		{
			try
			{
				int cache=cmpin(a[i][0],b[0]);
				if(cache!=-1)
				{
					string ca=b[0];
					for(int j=cache,k=0;j<cache+ca.size();++j,++k)
					{
						try
						{
							ca[j]=a[i][1][k];
						}
						catch(...)
						{
							continue;
						}
					}
					if(ca==a[i][1])
					{
						++ans;
					}
				}
			}
			catch(...)
			{
				cout << 0 << endl;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

