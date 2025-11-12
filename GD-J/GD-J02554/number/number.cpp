#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10000],n,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=1;
	for(int i=0;i<s.size();i++)
	{if(s[i]<='9'&&s[i]>='0'){a[n]=s[i]-'0';n++;}}
	n--;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{if(a[j]<a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}
