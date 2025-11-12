#include<bits/stdc++.h>
using namespace std;
int const N=2000005;
int a[N];
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int t=s.size(),ans=0;
	for(int i=0;i<t;i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
			a[++ans]=int(s[i])-48;
    }
    sort(a+1,a+ans+1,cmp);
    if(a[1]==0)
		cout<<0<<endl;
	else
		for(int i=1;i<=ans;i++)
			cout<<a[i];
	return 0;
}
