#include<bits/stdc++.h>
using namespace std;

bool cmp(short a,short b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	short a[1000001];
	string s;
	int i,j=1,si;
	
	cin>>s;
	si=s.size();
	for(i=0;i<=si-1;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[j]=s[i]-'0',j++;
	sort(a+1,a+j+1,cmp);
	for(i=1;i<=j-1;i++)
		cout<<a[i];
	
	return 0;
}
