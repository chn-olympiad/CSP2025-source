#include<bits/stdc++.h>
using namespace std;
long long n=0,a[10000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[n]=(s[i]-'0');
			n++;
			
		}
	}
	sort(a,a+n);
	for(long long i=n-1;i>=0;i--){
		cout<<a[i]; 
	}
	return 0;
} 
