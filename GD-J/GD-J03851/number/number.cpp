#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
void check(char x){
	if('0'<=x&&x<='9'){
		a[x-'0']++;
	}else{
		return;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		check(s[i]);
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 
