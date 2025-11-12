#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t="";
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t+=s[i];
		}
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	if(t[0]=='0') cout<<0<<endl;
	else cout<<t<<endl;
	return 0;
}
