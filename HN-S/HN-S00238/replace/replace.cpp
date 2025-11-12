#include<bits/stdc++.h>
//#define ull unsigned long long
using namespace std;
const int maxn=1e5+10;
//const ull p=13331;
//int ha[maxn];
string s1[maxn],s2[maxn];
//int get_hash(string s)
//{
//	ull res=0;
//	for(int i=0;i<s.size();i++)
//	{
//		res=res*p+s[i];
//	}
//	return res;
//}
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int res=0,l=t2.size();
		for(int len=1;len<=l;len++)
		{
			for(int i=0;i+len-1<l;i++)
			{
				string x=t2.substr(0,i);
				string y=t2.substr(i,len);
				string z=t2.substr(i+len);
				for(int k=1;k<=n;k++)
				{
					if(s2[k]==y)
					{
						if(x+s1[k]+z==t1)
						{
							res++;
						}
					}
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
