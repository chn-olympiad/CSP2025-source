#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,q;
struct node{
	string str1,str2;
};
vector<node>vect;
string mst;
map<string,string>mp;
int check(int tmp)
{
	string msz=vect[tmp].str1;
	for(int i=0;i<msz.length();i++)
	{
		int s=i;
		for(int j=0;j<mst.length();j++)
		{
			
			if(msz[s]!=mst[j])break;
			if(j==mst.length()-1)return i;
			else s++;
		}
	}
	return -1;
}
bool check2(string str1,string str2)
{
	if(str1.length()!=str2.length())return 0;
	for(int i=0;i<str1.length();i++)
	{
		if(str1[i]!=str2[i])return 0;
	}
	return 1;
}
void solve()
{
	//必须要包含的部分
	vect.clear();
	string str1,str2;cin>>str1>>str2;
	mst="";
	if(str1.length()!=str2.length())
	{
		if(mp[str1]==str2)cout<<1<<endl;
		else cout<<0<<endl;
	}
	else
	{
		bool fg=0;int st=0,en=str1.length()-1;
		for(int i=0;i<str1.length();i++)
		{
			if(fg==1&&str1[i]!=str2[i])en=i;
			if(str1[i]!=str2[i]&&fg==0)
			{
				fg=1;
				st=i;
			}
		}
		for(int i=st;i<=en;i++)mst+=str1[i];//找出必须包含的部分 
//		cout<<mst;
		int res=0;
		for(int i=0;i<n;i++)
		{
//			cout<<" "<<mst<<" "<<vect[i].str1<<" ";
			int ds=check(i);//第ds位能匹配上 
//			printf("第%d位能匹配上\n",ds);
			if(ds!=-1)
			{
//				cout<<"They could match\n";
				string cc="";
				int nst=st-ds,nen=en+vect[i].str1.length()-mst.length()-ds;
				for(int i=0;i<nst;i++)cc+=str1[i];
				cc+=mp[vect[i].str1];
				for(int i=nen+1;i<str1.length();i++)cc+=str1[i];
//				cout<<cc<<" "<<str2<<"------matching\n";
				if(check2(cc,str2)==1)
				{
//					cout<<"Congratuation\n";
					res++;
				}
			}
//			else cout<<"NO\n";
		}
		cout<<res<<endl;
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string str1,str2;cin>>str1>>str2;
		mp[str1]=str2;
		vect.push_back(node{str1,str2});
	}
	while(q--)
	{
		solve();
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
