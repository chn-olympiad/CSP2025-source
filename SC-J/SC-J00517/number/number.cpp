#include<bits/stdc++.h>
using namespace std;
int mx,cnt,a[1000000];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='1' && s[i]<='9') a[i]=int(s[i])-48;
		else if(s[i]=='0') cnt++;
	}sort(a,a+1000000);
	for(int i=999999;;i--){
		if(a[i]==0) break;
		cout<<a[i];
	}for(int i=1;i<=cnt;i++) cout<<0;
	return 0;
}