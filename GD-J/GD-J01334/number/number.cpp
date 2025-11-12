//number able
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=17;
int n;
string s;
int k[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') k[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(k[i]--) cout<<i;
	}
	return 0;
}
