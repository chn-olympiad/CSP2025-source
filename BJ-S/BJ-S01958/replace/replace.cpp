#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string c[N],c1[N],t1,t2;
map<string,int> m;
bool v[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i]>>c1[i];
		if(m[c[i]]) v[i]=1;
		m[c[i]]=i;
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		int l=t1.size();
		int l1=t2.size();
		if(l!=l1)
		{
			cout<<0<<"\n";
			continue;
		}
		int p=0,p1=0;
		bool F=0;
		for(int i=0;i<l;i++)
		{
			if(t1[i]!=t2[i]&&F==1) p1=i;
			else if(t1[i]!=t2[i]) p=i,F=1;
		}
	//	cout<<p1<<endl;
	//	string ss="",ss1="";
		for(int i=0;i<=p;i++)
		{
			string s="",s1="";
			for(int j=i;j<l;j++)
			{
				s+=t1[j];
				s1+=t2[j];
				if(j>=p1)
				{
					if(m[s]&&v[m[s]]!=1)
					{
						//cout<<c1[m[s]]<<" "<<s1<<endl;
						if(c1[m[s]]==s1) ans++;
					}
					else if(m[s])
					{
						for(int k=1;k<=n;k++)
						{
							if(c1[k]==s1) ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
