#include<bits/stdc++.h>
using namespace std;
#define int long long
struct bian
{
	string s1,s2;
}change[200001];
string have="",different;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int yes=0,n,q,sum=0;
	cin>>n>>q;
	for (int i=1;i<=n;i++)cin>>change[i].s1>>change[i].s2,have+=change[i].s1[0];
	string need,now,want;
	while (q--)
	{
		different="";
		yes=sum=0;
		cin>>now>>want;
		if (now.size()!=want.size())
			{
			cout<<0<<endl;
			continue;
			}
		/*for (int i=1;i<=n;i++)
			{
			if (now==change[i].s1&&want==change[i].s2)
				{
				sum++;
				break;
				}
			} */
		int buyiyang=0,start;
		for (int i=0;i<now.size();i++)
			{
			if (now[i]!=want[i])
				buyiyang=1,different+=now[i],start=i;
			else if (buyiyang==1)
					different+=now[i],buyiyang=0;
			}
		if (buyiyang==0)different.erase(different.size()-1,1);
		//cout<<different<<endl;
		for (int i=1;i<=n;i++)
			{
			int x=change[i].s1.find(different);
			yes=0;
			if (x!=string::npos)
				{
				/*if (change[i].s1==different)
					{
					sum++;
					continue;
					}*/
				if (start-x-1<0)continue;
				for (int j=start-x-1,k=0;k<change[i].s2.size();k++,j++)
					{
					if (change[i].s1[k]!=now[j]||change[i].s2[k]!=want[j])
						{
						yes=1;
						break; 
						} 
					}
				if (yes==1)continue;
				sum++;
				}
			}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
