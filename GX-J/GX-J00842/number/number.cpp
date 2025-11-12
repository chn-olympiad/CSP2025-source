#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    if(x>y) return true;
    else return false;
}
string s;
int n,k=-1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	int a[n];
	for(int i=0;i<n;i++)
	{
		if(int(s[i])-48>=0&&int(s[i])-48<=9)
		{
			k++;
			a[k]=int(s[i])-48;
		}
	}
	sort(a,a+k+1,cmp);
	for(int i=0;i<=k;i++) cout<<a[i];
	return 0;
}
