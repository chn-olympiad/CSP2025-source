#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	memset(a,0,sizeof(a));
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]>0)cout<<i,a[i]--;
	return 0;
}
