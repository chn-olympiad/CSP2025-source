#include <bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[++cnt]=s[i]-48;
		}
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
