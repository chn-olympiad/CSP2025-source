#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[1000005];
map<ll,ll>cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	ll l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			printf("%d",i);
		}
	}
}
