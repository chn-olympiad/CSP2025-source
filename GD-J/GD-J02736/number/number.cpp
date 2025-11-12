#include<bits/stdc++.h>
using namespace std;
string s;
char t;
int f[15],sum,len;
//f[]数字出现次数 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		t=s[i];
		if(t>='0'&&t<='9') 
		{
			sum=int(t-'0');
			f[sum]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(f[i]==0) continue;
		for(int j=1;j<=f[i];j++)
			cout<<i;
	}
	return 0;
}
