#include<bits/stdc++.h>
using namespace std; 
string s;
long long arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	long long n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0' && s[i]<='9'){
			arr[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		long long now=arr[i];
		while(now){
			now--;
			printf("%lld",i);
		}
	}
	return 0;
}
