#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string t1,t2;
struct doublstr
{
	string str1,str2;
	int longsize=0;
}replment[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>replment[i].str1>>replment[i].str2;
		replment[i].longsize=replment[i].str1.size();
	}
	while(q--)
	{
		cin>>t1>>t2;
		cnt=0;
		int l1=t1.size(),l2=t2.size();
		if(l1==l2)
		{
			for(int i=1;i<=n;i++)
			{
				
				int l=replment[i].longsize;
				for(int j=0;j<=l1-l;j++)
				{
					string ret1=t1,ret2=t2;
					if(replment[i].str1[0]==ret1[j])
					{
						for(int k=0;k<l;k++)
						{
							if(replment[i].str1[k]!=ret1[j+k])
							{
								break;
							}
							ret1[j+k]=replment[i].str2[k];
						}
						if(ret1==ret2) cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
}
