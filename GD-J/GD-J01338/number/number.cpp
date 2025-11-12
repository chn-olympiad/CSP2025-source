#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int w[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(char i:s){
		if('0'<=i&&i<='9') w[i-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=w[i];j++) cout<<i;
	}
	return 0;
}
