#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	string s;
	cin>>s;
	int a[11] = {};
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[s[i]-'0']++;
		}
	}
	for(int i = 9;i > -1;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	cout<<'\n';
	return 0;
} 