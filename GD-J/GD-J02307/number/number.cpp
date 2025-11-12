#include<bits/stdc++.h>
using namespace std;
string str;
vector<char>a;
bool cmp(char x,char y){return x>y;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>str;
	for(int i=0;i<(int)str.size();i++)
		if(str[i]>='0'&&str[i]<='9')
			a.push_back(str[i]);
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<(int)a.size();i++)
		cout<<a[i];
	return 0;
}
