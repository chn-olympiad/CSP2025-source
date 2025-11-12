#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("mumber.std.in");
	freopen("mumber.std.out");
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.length();i++){
		if(s[i]<'a'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
