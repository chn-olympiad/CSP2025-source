#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100008];
	int n=s.size();
	for(int i=0;i<=1004;i++)
	{
		a[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') a[i]=0;
		if(s[i]=='3') a[i]=3;
		if(s[i]=='2') a[i]=2;
		if(s[i]=='1') a[i]=1;
		if(s[i]=='6') a[i]=6;
		if(s[i]=='5') a[i]=5;
		if(s[i]=='4') a[i]=4;
		if(s[i]=='7') a[i]=7;
		if(s[i]=='8') a[i]=8;
		if(s[i]=='9') a[i]=9;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=-1) cout<<a[i];
	}
	return 0;
	}

