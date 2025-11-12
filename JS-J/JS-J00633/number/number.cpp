#include<bits/stdc++.h>
//tot_get:100
using namespace std;
int h[10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(isdigit(s[i])){
			h[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=h[i];j++){
			cout<<i;
		}
	}
	cout<<'\n';
	return 0;
}
