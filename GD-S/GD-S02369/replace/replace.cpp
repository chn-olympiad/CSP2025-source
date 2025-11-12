#include<bits/stdc++.h>
using namespace std;
int n,q;
struct id{
	string a,b;
};
string t1,t2;
string a[100001],b[100001];
vector<int>ti;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
//		id x={a,b};
	}
	while(q--)
	{
		cin>>t1>>t2;
		int ans=0;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=i;j<t1.size();j++)
			{
				string sb="",qian="",hou="";
				for(int k=0;k<i;k++) qian=qian+t1[k];
				for(int k=i;k<=j;k++) sb=sb+t1[k];
				for(int k=j+1;k<t1.size();k++) hou=hou+t1[k];
				for(int k=1;k<=n;k++)
				{
					if(sb==a[k])
					{
						sb=b[k];
						if(qian+sb+hou==t2) ans++;
						sb=a[k];	
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
