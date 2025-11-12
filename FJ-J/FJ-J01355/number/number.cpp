#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=cnt[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
