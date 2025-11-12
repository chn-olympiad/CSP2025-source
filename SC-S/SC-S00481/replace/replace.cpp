#include <bits/stdc++.h>
using namespace std;
const int N=2e5+99;
string s1[N],s2[N];
char t1[N],t2[N];
int n,m;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		for (int i=0;i<m;i++)
		{
			cin>>t1[i]>>t2[i];
			int sum=0;
			for (int j=0;j<n;j++)
			{
				int f1=t1[i].find(s1[j]);
				int f2=t2[i].find(s2[j]);
				if (f1==f2&&f1!=-1)
				{
					string d1=t1[i]d2=t2[i];
					int len=s1[i].size();
					d1.erase(f1,len);
					d2.erase(f1,len);
					if (d1==d2)
					{
						sum++;
					}
				}
			}
		 } 
	}
	cout<<sum<<endl;
}