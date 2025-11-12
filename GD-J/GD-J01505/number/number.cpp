#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(long long i = 9;i>=0;i--){
		long long cnt = a[i];
		for(long long j = 1;j<=cnt;j++){
			cout<<i;
		}
	}
	return 0;
} 
