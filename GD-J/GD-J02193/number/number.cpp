#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll i,j,x,cnt[10];
bool ok;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	for(i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9')
	{
		x=s[i]-'0';
		cnt[x]++;
	}
	for(i=9;i>=1;i--) for(j=1;j<=cnt[i];j++)
	{
		cout<<i;
		ok=true;
	}
	if(ok) for(i=1;i<=cnt[0];i++) cout<<0;
	else cout<<0;
	return 0;
}
