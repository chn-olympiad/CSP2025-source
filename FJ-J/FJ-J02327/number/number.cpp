#include<bits/stdc++.h>
using namespace std;
string s;
int num[10],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[s[i]-'0']++;
	for(int i=9;i>=1;i--)
		while(num[i])cout<<i,num[i]--,cnt++;
	if(!cnt)num[0]=1;
	while(num[0])cout<<0,num[0]--;
	return 0;
}