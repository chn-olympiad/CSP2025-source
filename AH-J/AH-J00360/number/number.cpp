#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') b+=s[i];
	}sort(b.begin(),b.end(),cmp);
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
