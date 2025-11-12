#include<bits/stdc++.h>
using namespace std;
string a[5000001][2],b,c;
int n,q,ans;
string part(string a,int l,int r)
{
	string b="";
	for(int i=l;i<r;i++)
		b+=a[i];
	return b;
}

void getAns()
{
	string d;
	int x=b.length();
	int y=a[0][0].length();
	for(int j=0;j<n;j++)
	{
		y=a[j][0].length();
		if(y>x) continue;
		for(int i=0;i<x-i;i++)
		{
			d="";
			if(x-i>=y)
			{
				string u=part(b,0,i),v=part(b,y+i,x);
				if(a[j][0]==part(b,i,y+i))
					d=u+a[j][1]+v;
				//cout<<a[j][0]<<"-"<<part(b,i,y+i)<<endl;
			}
			if(d==c) ans++;
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1];
	for(int i=0;i<q;i++)
	{
		ans=0;
		cin>>b>>c;
		getAns();
		cout<<ans<<"\n";
	}
	return 0;
}
