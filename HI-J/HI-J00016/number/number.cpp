#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char wjj[10001];
	cin>>s;
	int x=s.size();
	for(int i=0;i<x;i++)
	if(s[i]>='0'&&s[i]<='9')
	{
		wjj[cnt]=s[i];
		cnt++;
	}
	for(int i=0;i<cnt;i++)	for(int j=0;j<i;j++)	if(wjj[j]<wjj[i]) swap(wjj[j],wjj[i]);
	for(int i=0;i<cnt;i++)	cout<<wjj[i];
 	return 0;
}

