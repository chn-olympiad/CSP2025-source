#include<bits/stdc++.h>
using namespace std;
long long k,a[1000100],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if((s[i]>='0')&&(s[i]<='9')){
			n++;
			a[n]=((int)s[i]-48);
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
