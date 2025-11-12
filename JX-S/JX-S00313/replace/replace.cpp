#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1[200010],s2[200010],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cnt=0;
		cin>>t1>>t2;
		int T=t1.size(),TT=t2.size();
		if(T!=TT)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int S=s1[i].size();
			int j=0,sj=-1;
			for(int l=0;l<T;l++)
			{
				if(t1[l]==s1[i][j] && t2[l]==s2[i][j])
				{
					j++;
				}
				else j=0,sj=j;
				if(j-sj==S)
				{
					bool flag=1;
					for(int k=l+1;k<T;k++)
					{
						if(t1[k]!=t2[k])flag=0;
					}
					if(flag)cnt++;
					break;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

