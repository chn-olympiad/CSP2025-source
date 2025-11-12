#include<bits/stdc++.h>
using namespace std;
#define int long long 
string a;
priority_queue<int,vector<int>,less<int>>q; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int sizea=a.size();
	for(int i=0;i<sizea;i++)
	{
		if(a[i]>=0&&a[i]<='9')
		{
			q.push(a[i]-'0'); 
		}
	}
	while(q.size())
	{
		int c=q.top();
		q.pop();
		cout<<c;
	}
	return 0;
}
