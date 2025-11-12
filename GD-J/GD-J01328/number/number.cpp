#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000001];
long long pos=1;
long long n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[pos]=s[i]-'0';
			pos++;
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
