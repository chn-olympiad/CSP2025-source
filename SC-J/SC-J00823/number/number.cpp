#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

string s;
char ans[1000100];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[t]=s[i];
			t++;
		}
	}
	sort(ans,ans+t);
	if(ans[t-1]=='0'){
		cout<<"0";
	}
	else{
		for(int i=t-1;i>=0;i--){
			cout<<ans[i];
		}
	}
	return 0;
}