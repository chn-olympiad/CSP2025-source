#include<bits/stdc++.h>
using namespace std;
vector<int>a;
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)if(s[i]>='0'&&s[i]<='9')
	{
		a.push_back((s[i]-'0'));
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<a.size();i++)printf("%d",a[i]);
	return 0;
}
/*
ÎÒµÄÊÖÍó°¡ 
*/
