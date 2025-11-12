//GZ-S00426 遵义市第四中学 赵振宇
#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string l1,l2;
map<int,string> mp1;
map<string,string> mp2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>l1>>l2;
		mp1[i]=l1;
		mp2[l1]=l2;
	}
	while(q--)
	{
		ans=0;
		cin>>l1>>l2;
		for(int i=1;i<=n;i++)
		{
			string x=mp2[mp1[i]];
			int re=l1.find(mp1[i]);
			if(re!=-1)
			{
				string a="",b="";
				for(int i=0;i<re;i++)
					a+=l1[i];
				for(int i=re+x.size();i<l1.size();i++)
					b+=l1[i];
				if((a+x+b)==l2)
				{
					ans++;
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

