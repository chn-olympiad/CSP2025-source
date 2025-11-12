#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string s;
long long ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	string ch;
	int len=s.size();
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
			ch[i]++;
		ch[i]=ch[i+1];
		if(ch[i]<ch[i+1])
		{
			swap(ch[i],ch[i+1]);
			cout<<ch[i+1];
		}
		if(ch[i]>ch[i+1])
		{
			cout<<ch[i];
		}
	}
	return 0;
}
