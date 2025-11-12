#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
string s[200010][3];
int p[5000010],d[200010][3],f1[5000010],f2[5000010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,t;
	string g1,g2;
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=5000000;i++)
		p[i]=p[i-1]*26%998244353;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		for(int j=0;j<(int)s[i][1].size();j++)
			(d[i][1]+=(s[i][1][j]-'a')*p[j]%998244353)%=998244353;
		for(int j=0;j<(int)s[i][2].size();j++)
			(d[i][2]+=(s[i][2][j]-'a')*p[j]%998244353)%=998244353;		
	}
	while(q--)
	{
		cin>>g1>>g2;
		if((int)g1.size()!=(int)g2.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<(int)g1.size();j++)
		{
			if(j>0)
				f1[j]=(f1[j-1]+(g1[j]-'a')*p[j]%998244353)%998244353;
			else
				f1[j]=(g1[j]-'a')*p[j]%998244353;		
		}
		for(int j=0;j<(int)g2.size();j++)
		{
			if(j>0)
				f2[j]=(f2[j-1]+(g2[j]-'a')*p[j]%998244353)%998244353;
			else
				f2[j]=(g2[j]-'a')*p[j]%998244353;		
		}	
		t=0;
		for(int i=0;i<(int)g1.size();i++)
			for(int j=1;j<=n;j++)
				if((int)s[j][1].size()+i<=(int)g1.size()&&d[j][1]*p[i]%998244353==(f1[(int)s[j][1].size()+i-1]-(i>0?f1[i-1]:0ll)+998244353)%998244353&&(d[j][2]*p[i]%998244353+f1[(int)g1.size()-1]-f1[(int)s[j][2].size()+i-1]+(i>0?f1[i-1]:0ll)+998244353)%998244353==f2[(int)g2.size()-1])
				{
					t++;				
				}

		cout<<t<<'\n';	
	}
	return 0;
}

