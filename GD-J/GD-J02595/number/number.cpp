#include<bits/stdc++.h>
using namespace std;
string s,a;
long long si,ans[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	si=s.size();
	for(int i=0;i<si;i++){
		if(s[i]>='0' && s[i]<='9') ans[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(ans[i]==0) continue;
		for(int j=1;j<=ans[i];j++){
			a+=(i+'0');
		} 
	}
	if(a[0]=='0'){
		cout<<0;
		return 0;
	}
	cout<<a;
	return 0;
}
