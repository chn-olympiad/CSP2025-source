#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000010;
char s[MAX_N];
long long a[15],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=strlen(s); 
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i; 
	}
	return 0;
}