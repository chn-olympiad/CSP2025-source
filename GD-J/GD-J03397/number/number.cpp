#include<bits/stdc++.h>
#define int long long
using namespace std;
string a;
int m[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a;
	for(char c:a){
		if(isdigit(c))m[c-'0']++;
	}
//	int ans=0;
	for(int i=9;i>=0;i--){
		if(!m[i]){
			continue;
		}
		for(int k=1;k<=m[i];k++){
			cout<<i;
		}
	}
}
