#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,b[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]!=0){
			if(b[i]>=10){
				printf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",i,i,i,i,i,i,i,i,i,i);
				b[i]-=10;
			}
			else{
				printf("%lld",i);
				b[i]--;	
			}
		}
	}
	return 0;
}
