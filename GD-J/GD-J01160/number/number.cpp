#include<bits/stdc++.h>
using namespace std;
string s,q;
long long n,a[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size()-1;
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[s[i]]++;
	}
	for(char i='9';i>='0';i--)
	{
		for(int j=1;j<=a[i];j++)q+=i;
	}
	if(q[0]=='0')cout<<0;
	else
	cout<<q;
	
	return 0;
} 
