#include<bits/stdc++.h>
using namespace std;

string nim="MMMMMMMMMMMMMMMMMMMMMMMM";
int n,q;

vector<string>a,b;

bool ifin(string myc); 

bool cmp(string mya,string myb)
{
	int size=mya.size();
	string tmp="";
	char cmya[size];
	for(int i=0;i<size;i++)
	{
		cmya[i]=mya[i];
	}
	for(int i=0;i<size;i++)
	{
		tmp="";
		for(int j=i;j<size;j++)
		{
			tmp.push_back(mya[j]);
			if(tmp==myb)
			{
				if(nim.length()>tmp.length() && ifin(tmp)) nim=tmp;
			}
		}
	}
	if(nim=="") return 0;
	else return 1;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	a.resize(n);
	b.resize(n);
	string c[q],d[q];
	
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	for(int i=0;i<q;i++) cin>>c[i]>>d[i];

	int ans;
	
	for(int i=0;i<q;i++)
	{
		if(cmp(c[i],d[i]))
		{
			cout<<nim.length()<<endl;
		}
		cout<<nim;
	}
	return 0;
}

bool ifin(string myc)
{
	for(int i=0;i<n;i++)
	{
		if(myc==a[i]) return 1;
	}
	return 0;
}
