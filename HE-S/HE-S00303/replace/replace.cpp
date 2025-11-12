#include<bits/stdc++.h>
using namespace std;
set<pair<string,string> >s;
//plaese give me pts
//1402105 HJYH012(wslz)
//And testify - Never notice me...
//plase die little dreams
//j300+ is good,and s100 is also good,sT1 is so easy,A it at 16:00
//Okay at 18:25
int a1[5000100],a2[5000100];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a,b;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		s.insert(make_pair(a,b));
	}
	for(int i=1;i<=q;i++)
	{
		long long sum=0;
		cin>>a>>b;
		int len=a.size();
		for(int i=0;i<len;i++)
			for(int j=1;j<=len-i;j++)
				if((i==0||a.substr(0,i)==b.substr(0,i)) && (j==len-i||a.substr(i+j,len)==b.substr(i+j,len)) && s.find(make_pair(a.substr(i,j),b.substr(i,j)))!=s.end())
					sum++;//cout<<a.substr(i,j)<<' '<<b.substr(i,j)<<endl;
		cout<<sum<<endl;
	}
	return 0;
}
