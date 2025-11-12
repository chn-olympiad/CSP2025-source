#include <bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	for(size_t i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
