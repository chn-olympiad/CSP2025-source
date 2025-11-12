#include<bits/stdc++.h>
using namespace std;
string s;
int f[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int n=int(s[i]-'0');
			f[n]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(f[i]>=1){
			int q=f[i];
			while(q--){
				cout<<i;
			}
		}
	}
	return 0;
} 
