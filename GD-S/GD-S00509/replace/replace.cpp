#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct node{string u,v;};bool operator <(node a,node b){return a.u<b.u;}
int n,q,cur;
string t1,t2;
map<string,int>mp;
vector<string>v[100005];
bool find(vector<string>kkk,string tar)
{
	for(string i:kkk)if(i==tar)return 1;
	return 0;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i<=n;i++)
	{
		cin >> t1 >> t2;
		if(!mp[t1])mp[t1]=++cur;
		v[mp[t1]].push_back(t2);
	}
	while(q--)
	{
		int ans=0;
		cin >> t1 >> t2;
		if(t1.size()!=t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		t1=' '+t1+' ';
		t2=' '+t2+' ';
		for(int i = 0;1;i++)
		{
			if(t1.substr(0,i+1)!=t2.substr(0,i+1))break;
			for(int j = t1.size()-1;1;j--)
			{
				if(t1.substr(j,t1.size()-j)!=t2.substr(j,t1.size()-j))break;
//				cout << t1.substr(i+1,j-i-1) << ' ' << t2.substr(i+1,j-i-1) << endl;
				if(mp[t1.substr(i+1,j-i-1)] && find(v[mp[t1.substr(i+1,j-i-1)]],t2.substr(i+1,j-i-1)))ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

