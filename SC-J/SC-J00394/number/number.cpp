#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";cin>>s;
	int a[10]={0};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)ans+=(i+'0');
	}
	cout<<ans;
	return 0;
}