#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(int(s[i])-48>=0&&int(s[i])-48<=9){
			a[n]=s[i];
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i]-48;
	}
	return 0;
}
