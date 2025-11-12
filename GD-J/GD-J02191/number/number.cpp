#include<bits/stdc++.h>
using namespace std;
string s;
long long i,j,a[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=a[i];j++){
			printf("%lld",i);
		}
	}
	return 0;
} 
