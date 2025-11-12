#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++){
		a[i]=0;
	}
	string s;
	int ans=0;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&& s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=1;i--){
		while(a[i]--){
			ans++;
			cout << i;
		}
	}
	if(ans){
		while(a[0]--){
			cout << 0;
		}
	}
	else{
		if(a[0]){
			cout <<0;
		}
	}
	return 0;
}
