#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char num[N];int n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++)
	{
		if(s[i]>='0'&&s[i]<='9')num[++n]=char(s[i]);
	}
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;i++)putchar(num[i]);
	return 0;
}
