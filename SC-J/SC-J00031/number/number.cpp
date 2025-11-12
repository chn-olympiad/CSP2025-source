#include<bits/stdc++.h>
#define ll long  long
using namespace std;
string s;
int f[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') f[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(f[i]--){
			cout<<i;
		}
	}
	return 0;
}


