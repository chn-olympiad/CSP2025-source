#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string a,b;
	for(int i=1;i<=s.size();i++){
		a[i]=s[i];
	}
	for(int i=s.size();i>=1;i--){
		for(int j=1;j<=s.size();j++){
			b[j]=a[i];
		}
	}
	for(int i=1;i<=s.size();i++){
		cout<<b[i];
	}
	return 0;
}
