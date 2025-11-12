#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int ss;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss++;
			a[ss]=s[i]-'0';
		}
	}
	sort(a+1,a+ss+1);
	for(int i=ss;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
