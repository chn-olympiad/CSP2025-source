#include<bits/stdc++.h>
using namespace std;
int a,b,d,p=0;
vector<int> c;
vector<int> l;
vector<vector<int>> e;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b;
		for(int j=0;j<b;j++)
		{
			for(int k=0;k<3;k++){
				cin>>d;
				c.push_back(d);}
			sort(c.begin(),c.end());
			l.push_back(c[2]);
			c.clear();}
		for(int j=0;j<b;j++) p+=l[j];
		cout<<p<<endl;
		l.clear();
	}
	return 0;
	
}
