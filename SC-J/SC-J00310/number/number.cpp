#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n,t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			int k=s[i]-'0';
			t[k]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]--) cout<<i;
	}
	return 0;
}