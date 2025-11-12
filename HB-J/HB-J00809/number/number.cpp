#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	for(int i=0;i<s.end()-s.begin();i++){
		if(s[i]>='0' && s[i]<='9'){
			a+=s[i];
		}
	}
	sort(a.begin(),a.end());
	for(int j=a.end()-a.begin();j>=0;j--){
		cout<<a[j];
	}
	return 0;
}
