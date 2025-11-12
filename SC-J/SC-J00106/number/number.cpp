#include<bits/stdc++.h>
using namespace std;
long long a[1000005],o;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			o++;
			a[o]=s[i]-'0';
		}
	}
	sort(a+1,a+o+1);
	if(a[o]==0){
		cout<<0;
		return 0;
	} 
	for(int i=o;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 