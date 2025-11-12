#include<bits/stdc++.h>
using namespace std;
int a[30];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	int flag=1;
	for(int i=9;i>=1;i--){
		if(a[i]){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
