#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],o=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			o++;
			a[o]=s[i]-'0';
		}
	}
	cout<<o<<endl;
	sort(a+1,a+o+1);
	for(int i=o;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
