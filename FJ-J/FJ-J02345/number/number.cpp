#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000020],n,js;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;++i){
		s[i]=a[i]-48;
	}
	sort(s,s+n);
	for(int i=n-1;i>=0;--i){
		if(s[i]<=9&&s[i]>=0){
			cout<<s[i];
		}
	}
	return 0;
} 
