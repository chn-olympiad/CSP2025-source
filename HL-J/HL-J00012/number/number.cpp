#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int x;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]>='0'&&s[i]<='9')
    	{
    		a[x]=s[i]-'0';
    		x++;
		}
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++) cout<<a[i];
	return 0;
}