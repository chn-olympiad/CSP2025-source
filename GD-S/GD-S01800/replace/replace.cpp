#include<iostream>
#include<string>
#include<queue>

using namespace std;

string a[100005],b[100005];

int n,p;

string x,y;

int ans=0;

string replace(string s,string l,int a,int b)
{
	s.erase(a,b);
	
	s.insert(a,l);
	
	return s;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>p;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	
	while(p--)
	{
		ans=0;
		
		cin>>x>>y;
		
		for(int i=1;i<=n;i++)
		{
			string ns;
			
			if(x.find(a[i])!=x.npos)
			{
				ns=(replace(x,b[i],(int)x.find((string)a[i]),(int)a[i].size()));
			}
			
			if(ns==y)
			{
				ans++;
			}
		}
		
		cout<<ans<<endl;
	}
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
