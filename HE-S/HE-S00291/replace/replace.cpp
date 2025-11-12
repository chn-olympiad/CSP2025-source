#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int n,q;
string s1,s2;
string t1,t2;
map<string,int> m;
vector<string> way[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	//记得解注释!!!!!!!
	int cnt=1;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		if(!m[s1])
		{
			m[s1]=cnt;
			way[m[s1]].push_back(s2);
			cnt++;
		}
		else
		{
			way[m[s1]].push_back(s2);
		}
	}
	//显然的 如果询问的两个字符串长度不同 则无解
	//其次，这里可以到达的string其实可能有多个
	//我还是vector一下吧 
	
	//把第一个不一样的和最后一个不一样的作为两个端点
	//枚举所有包含这一大段的子串 
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		long long ans=0;
		int kan1=t1.size();
		int kan2=t2.size();
		if(kan1!=kan2)
		{
			cout<<0<<'\n';
			continue;
		}
		int l=0;
		int r=0;
		string pan="";
		string check="";
		for(int z=0;z<t1.size();z++)
		{
			if(t1[z]!=t2[z])
			{
				l=z;
				break;
			}
		}
		for(int z=t1.size()-1;z>=0;z--)
		{
			if(t1[z]!=t2[z])
			{
				r=z;
				break;
			}
		}
		for(int z=l;z<=r;z++)
		{
			pan+=t1[z];
			check+=t2[z];
		}
		for(int zuo=0;zuo<=l;zuo++)
		{
			for(int you=r;you<t1.size();you++)
			{
				string xuan=pan;
				string jiancha=check;
				for(int jial=l-1;jial>=zuo;jial--)
				{
					xuan=t1[jial]+xuan;
					jiancha=t2[jial]+jiancha;
				}
				for(int jiar=r+1;jiar<t1.size();jiar++)
				{
					xuan=xuan+t1[jiar];
					jiancha=jiancha+t2[jiar];
				}
				int qu=m[xuan];
				if(!qu)continue;
				for(int z=0;z<way[qu].size();z++)
				{
					if(way[qu][z]==jiancha)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
