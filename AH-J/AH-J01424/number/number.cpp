#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>

using namespace std;
using LL =long long;
const LL N = 1e6+1;

string s,ans;
LL cnt[12];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL len=s.size()-1;
	for(int i=0;i<=len;i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	
	for(LL i=9;i>=0;i--)
		while(cnt[i]){
			ans+=i+'0';
			cnt[i]--;
		}
	
	cout<<ans;
	return 0;
}
