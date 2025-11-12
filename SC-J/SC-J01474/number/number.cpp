#include<bits/stdc++.h>
#define ll long long
#define jmy jiangmuyang
using namespace std;
const int MAXN=1e6+5;
int jmynum[10];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int jmylen=s.length();
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9') jmynum[s[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=jmynum[i];j++) cout<<i;
	}
	return 0;
}