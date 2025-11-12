#include <bits/stdc++.h>
using namespace std;

//baoli code(about 60pts)

int n,a[6000],cnt,s[6000],book[6000];

void dfs(int nmaxn,int nowc,int d,int sum,bool p)
{

	
	if (sum>nmaxn*2&&nowc>=3&&p)
	{
		cnt++;
		cnt%=998244353;
			//cout << '*' << d << ' ' << nowc << ' ' << sum << ' ' << nmaxn << "   ";
	//for (int i=1;i<=n;i++)cout << book[i];
	//cout << endl;
	}
	
	if (d==n+1)return;
	book[d]=1;
	dfs(max(nmaxn,a[d]),nowc+1,d+1,sum+a[d],1);
	book[d]=0;
	dfs(nmaxn,nowc,d+1,sum,0);


}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		//s[i]=s[i-1]+a[i];
	}
	//sort(a+1,a+n+1);
	/*for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			int allsum=s[j]-s[i-1];
			
		}
	}*/
	if (n<=25)
	{
		dfs(0,0,0,0,0);
		cout << cnt/2;		
	}else{
		unsigned long long ans=0;
		for (int i=3;i<=n;i++)
		{
			unsigned long long temp1=1;
			unsigned long long temp2=1;
			for (int j=n;j>=n-i+1;j--)
			{
				temp1*=j;
				temp1%=998244353;
			}
			for (int j=i;j>=1;j--)
			{
				temp2*=j;
				temp2%=998244353;
			}
			//cout << i << ' ' << temp1 << ' ' << temp2 << endl;
			ans += temp1/temp2;
		}
		cout << ans;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
