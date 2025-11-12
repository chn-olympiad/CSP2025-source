#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	 
	for(int i=1;i<=s.size();i++){
		if(s.front()<='9'&&s.front()>='0'){
			a[i]=s[i];
		}
	}
	sort(a+1,a+s.size()+1);
	for(int i=1;i<=s.size();i++){
		cout<<a[i]-'0';
	}
	return 0;
}
