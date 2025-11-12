#include<bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 10;
struct node
{
	string x,y;
};
vector<node> a;

int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		a.push_back({s1,s2});
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		for(auto op : a)
		{
			string x = op.x , y = op.y;
			
		}
	}
	return 0;
}//0pts
