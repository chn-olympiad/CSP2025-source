#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'<10&&s[i]-'0'>=0){
			a[++x]=s[i]-'0';
		}
	}
	sort(a+1,a+1+x);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
