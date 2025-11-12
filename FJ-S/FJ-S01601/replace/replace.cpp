#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio> 
#include <cstring>
using namespace std;
string a[200010][2];
int n,q;
int find(string s,string t,string u,string v)
{
	int pos1=0,pos2=0,sum=0;
	while((s.find(t,pos1)!=s.npos)&&(s.find(v,pos2)!=v.npos)&&pos1==pos2)
	{
		sum++;
		pos1=s.find(t,pos1)+t.size();
		pos2=u.find(t,pos2)+v.size();
		cout<<pos1<<' '<<pos2<<endl;
	}
	return sum;
} 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		int sum=0;
		for (int i=1;i<=n;i++)sum+=find(y,a[i][1],x,a[i][0]);
		cout<<sum<<endl;
	}
	return 0;
}
