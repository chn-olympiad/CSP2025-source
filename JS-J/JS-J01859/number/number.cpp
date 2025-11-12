#include<bits/stdc++.h>
using namespace std;
string s;
int bt[12],l;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(size_t i=0;i<s.size();i++){
		l=s[i]-'0';
		if(l>=0&&l<=9){
			bt[l]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=bt[i];j++){
			cout<<i;
		}
	}
	cout<<'\n';
	return 0;
}
