#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,ts[503],c[503],tong[503],tz[503];
long long ans;
string s;
int main()
{
	freopen("employ4.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		if(s[i]-'0'==1)	
			ans++;
	if(ans<m)
	{
		cout<<"0";
		return 0;
	}
	ans=0;
	int fq=0;
	for(int i=0;i<n;i++)
		if(s[i]-'0'==1)	
		{
			for(int i=1;i<=n;i++)
				if(c[i]>fq)
					ans++;
			ans%=998244353;
		}
		else
			fq++;
	if(m==1)
		cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
