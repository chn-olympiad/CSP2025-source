#include<bits/stdc++.h>
using namespace std;
int k=0;
string s;
char c[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') c[k++]=s[i];
	}
	sort(c,c+k,cmp);
	cout<<c;
	return 0;
}
