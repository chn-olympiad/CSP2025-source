#include <bits/stdc++.h>
using namespace std;
string str;
int l[1000005],n=0;
long long ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if((str[i]>='0')&&(str[i]<='9')) l[n++]=str[i]-'0'; 
	}
	sort(l,l+n);
	for(int i=n-1;i>=0;i--){
		cout<<l[i];
	}
	return 0;
}

