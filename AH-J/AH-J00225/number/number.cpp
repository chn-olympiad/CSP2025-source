#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	a="0";
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
		}
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
