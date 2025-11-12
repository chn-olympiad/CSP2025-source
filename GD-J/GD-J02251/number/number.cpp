#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()+1]={0},b=0;
	for(int i=0;i<s.size();i++){
		if(int(s[i]-'0')>=0&&int(s[i]-'0')<=9){
			a[i]=int(s[i]-'0');
			b++;
		}
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=s.size()-b;i--){
		cout<<a[i];
	}
	return 0;
}
