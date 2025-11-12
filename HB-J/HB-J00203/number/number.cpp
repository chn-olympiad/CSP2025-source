#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[15];
string s;
bool q=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(ll i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[int(s[i]-'0')]++;
			if(s[i]!='0')q=0;
		}
	}
	for(ll i=9;i>=0;i--){
		if(i==0&&q)cout<<'0';
		else for(ll j=1;j<=cnt[i];j++)cout<<i;
	}
    return 0;
}
