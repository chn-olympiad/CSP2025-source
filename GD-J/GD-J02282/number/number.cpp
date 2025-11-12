#include<bits/stdc++.h> 
using namespace std;
string s;int a[70],len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;len=s.length();
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]]++;
	}
	for(int i=57;i>=48;i--)
		for(int j=1;j<=a[i];j++)
			printf("%c",char(i));
}
