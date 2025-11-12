#include <bits/stdc++.h>
using namespace std;
string s;
int a[100],t;
long long ans=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=1;i--){
		while(a[i]--){
			t++;
			ans=ans*10+i;
			if(t==18){
				cout<<ans;
				t=0;
				ans=0;
			}
		}
	}
	if(ans!=0)
		cout<<ans;
	while(a[0]--){
		cout<<0;
	}
	return 0;
}
