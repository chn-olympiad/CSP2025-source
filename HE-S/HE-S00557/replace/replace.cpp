#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
const long long mod=1e9+7;
int t;
//记得检查盘，存盘，freopen，删注释，删文件 
int n,q,l[N],dis[N];
long long ans;
string s[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	bool okb=true;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i][1]>>s[i][0];
		int op=s[i][1].find("b");
		int op0=s[i][0].find("b");
		l[i]=op;
		dis[i]=op-op0;
		int opr=s[i][1].rfind("b");
		int op0r=s[i][0].rfind("b");
		if(op==-1||op!=opr||op0==-1||op0r!=op0)
		{
			okb=false;
		}
	}
	if(okb)
	{
		while(q--)
		{
			string t1,t0;
			ans=0;
			cin>>t1>>t0;
			int k1=t1.find("b");
			int k0=t0.find("b");
			int kk=k1-k0;
			for(int i=1;i<=n;++i)
			{
				if(dis[i]==kk&&k1>=l[i]&&t1.size()-k1>=s[i][1].size()-l[i])
				{
					ans++;
				}
			}
			cout<<ans;
			cout<<'\n';
		}
	}
	else
	{
		while(q--)
		{
			string t1,t0;
			cin>>t1>>t0;
			ans=0;
			for(int i=1;i<=n;++i)
			{
				if(s[i][1].size()<=t1.size())
				{
					int ok=t1.find(s[i][1],0);
					int ok1=t0.find(s[i][0],0);
					while(ok!=-1&&ok1==ok)
					{
						if(t1.substr(0,ok)!=t0.substr(0,ok)||t1.substr(ok+s[i][1].size(),t1.size()-ok-s[i][1].size())!=t0.substr(ok+s[i][1].size(),t1.size()-ok-s[i][1].size()))
						{
							break;
						}
						ans++;
						ok=t1.find(s[i][1],ok+1);
						ok1=t0.find(s[i][0],ok1+1);
					}
				}
			}
			cout<<ans;
			cout<<'\n';
		}
	}
//	cout<<'\n'<<"多组数据要换行&初始化"; 
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
	return 0;
}
//struct 
