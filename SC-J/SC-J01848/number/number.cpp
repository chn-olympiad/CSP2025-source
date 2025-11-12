#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum1=0;
string s;
int a[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0') {a[sum1]=0;sum1++;}
		if(s[i]=='1') {a[sum1]=1;sum1++;}
		if(s[i]=='2') {a[sum1]=2;sum1++;}
		if(s[i]=='3') {a[sum1]=3;sum1++;}
		if(s[i]=='4') {a[sum1]=4;sum1++;}
		if(s[i]=='5') {a[sum1]=5;sum1++;}
		if(s[i]=='6') {a[sum1]=6;sum1++;}
		if(s[i]=='7') {a[sum1]=7;sum1++;}
		if(s[i]=='8') {a[sum1]=8;sum1++;}
		if(s[i]=='9') {a[sum1]=9;sum1++;}
	}
	sort(a,a+sum1);
	for(int i=sum1-1;i>=0;i--) cout<<a[i];
	return 0;
}