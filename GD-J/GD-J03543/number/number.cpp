#include<bits/stdc++.h>
#define int long long
using namespace std;
void init(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
string s;
int a[10];
bool p;
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	init();
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
