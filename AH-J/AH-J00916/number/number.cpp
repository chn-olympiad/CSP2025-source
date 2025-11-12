#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	const int N=1e6+5;
	int a[N];
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') a[j++]=0;
		if(s[i]=='1') a[j++]=1;
		if(s[i]=='2') a[j++]=2;
		if(s[i]=='3') a[j++]=3;
		if(s[i]=='4') a[j++]=4;
		if(s[i]=='5') a[j++]=5;
		if(s[i]=='6') a[j++]=6;
		if(s[i]=='7') a[j++]=7;
		if(s[i]=='8') a[j++]=8;
		if(s[i]=='9') a[j++]=9;
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
