#include<bits/stdc++.h>
using namespace std;
string s;
int n,b[20],f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(f||i>=1)
		while(b[i]--){
			f=1;
			cout<<i;
		} 
	}
	if(f==0) cout<<0;
	return 0;
}