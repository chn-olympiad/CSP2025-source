#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll ans,tj[15],p,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	n=s.size();
	s='0'+s;
	for(ll i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			tj[s[i]-'0']++;
			if(s[i]>'0')p=1;
		}
	}
	if(!p)printf("0");
	else {
		for(ll i=9;i>=0;i--){
			while(tj[i]){
				printf("%lld",i);
				tj[i]--;
			}
		}
	}
	return 0;
}
