#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int tong[11];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			tong[x]++;
		} 
	}
	for(int i=9;i>=0;i--){
		if(tong[i]!=0){
			for(int j=1;j<=tong[i];j++){
				cout<<i;
			}
		}
	}
	
	return 0;
}
