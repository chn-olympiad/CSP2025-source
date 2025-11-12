#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

string s;
int a[10],len;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>s;
	len=s.size();
	s=' '+s;
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	
	return 0;
}