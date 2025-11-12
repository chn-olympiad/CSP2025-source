#include<bits/stdc++.h>
using namespace std;
int x[1000010],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			t++;
			x[t]=int(a[i])-48;
		}
	}
	sort(x+1,x+t+1);
	for(int i=t;i>=1;i--) cout<<x[i];
	return 0;
} 
