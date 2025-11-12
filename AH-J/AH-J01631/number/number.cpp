#include<bits/stdc++.h>
using namespace std;
string s;
int n,b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
		while(b[i]){
			cout<<i;
			b[i]--;
		}
	return 0;
}
