#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

int t[15];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]>0){
			for(int j=1;j<=t[i];j++){
				cout<<i;
			}
		}
	}
	
	return 0;
} 