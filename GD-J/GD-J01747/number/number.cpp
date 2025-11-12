#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[int(s[i]-'0')]++;
	int bj=1;
	//for(int i=0;i<=9;i++)cout<<a[i]<<" ";
	for(int i=9;i>=0;i--)
	{
		if(i!=0&&bj==1&&a[i]!=0)bj=0;
		if(i==0&&bj==1)
		{
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
} 
