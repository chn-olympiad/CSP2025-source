#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll us[11];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			us[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=us[i];j>0;j--){
			cout<<i;
		}
	}cout<<"\n";
	return 0;
} 
