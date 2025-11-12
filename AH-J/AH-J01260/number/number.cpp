#include <bits/stdc++.h>
using namespace std;
typedef long long L;
const L N=10;
int a[N];
int check(){
	bool o=0;
	for(int i=9;i>=0;i--){
		if(a[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(L i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int t=s[i]-'0';
			a[t]++;
		}
	}
	string ans="";
	char pos='9';
	while(check()){
		if(a[int(pos-'0')]){
			ans=ans+pos;
			a[pos-'0']--;
		}
		else{
			pos=char(int(pos-1));
		}
	}
	cout<<ans;
	return 0;
}
