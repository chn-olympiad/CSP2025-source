#include<bits/stdc++.h>
#define ll long long
const int k=1e6+19;
using namespace std;

string s;
char c;
ll n[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	int i=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		c=s[i];
		if(c>='0'&&c<='9'){
			n[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
}

