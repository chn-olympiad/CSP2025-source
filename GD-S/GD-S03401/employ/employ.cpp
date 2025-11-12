#include<iostream>
const int N = 1e5+10;
using namespace std;
int n,m,nx[N],sum = 0,k,b[N];
string s; 
void h(int jf,int step,int ans)
{
	if(ans == m)
	{
		k++;
		for(int i = 0;i<=n;i++)cout<<b[i]<<" ";
		return;
	}
	if(step > n)
	return;
	for(int i = 1;i<=n;i++)
	{
		int flag = 1;
		for(int j = 1;j<=ans;j++)
		if(b[j]==i)flag = 0;
		if(flag = 1)
		{
			if(nx[i]-jf>=0)
			{
				if(s[i]=='1')
				{
					b[ans] = i;
					h(jf,step+1,ans+1);
				}
				else
				{
					h(jf+1,step+1,ans);
				}
			}
			else h(jf+1,step+1,ans);
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; 
	for(int i = 1;i<=n;i++)cin>>nx[i];
	for(int i = 0;i<n;i++)
		if(s[i]=='1')sum++;
	if(sum<m)
	{
		cout<<0;
		return 0;
	}
	h(0,1,1);
	cout<<endl<<k%998244353;
	return 0;
 } 
