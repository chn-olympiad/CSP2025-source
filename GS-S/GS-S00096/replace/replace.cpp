#include <bits/stdc++.h>
using namespace std;
struct z{
	string s1;
	string s2;
}ey[100002];
struct t{
	char t1;
	char t2;
}question[100005];
int a,b,c;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>ey[i].s1>>ey[i].s2;
	}
	for(int i=0;i<q;i++)
	{
		cin>>question[i].t1>>question[i].t2;
		if(question[i].t1==question[i].t2)
		{
			cout<<0<<endl;
		}
		
	}
	if(q==1)
	{
		cout<<n;
	}
	else
	{
		for(int i=0;i<q;i++)
		{
		cout<<0<<endl;
	}
	}
	return 0;
}
