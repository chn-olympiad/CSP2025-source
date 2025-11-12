#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
			cnt++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>=1){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
