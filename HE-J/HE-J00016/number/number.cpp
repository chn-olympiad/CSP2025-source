#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
long long n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[n]=s[i]-48;
			n=n+1;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		cout<<a[i];
	}
	return 0;
} 

