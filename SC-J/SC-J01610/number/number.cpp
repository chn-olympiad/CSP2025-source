#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	int n=a.size();
	if(a[0]==0) cout<<0;
	else for(int i=0;i<n;i++) cout<<a[i];
	return 0;
} 