#include<bits/stdc++.h>
using namespace std;
string s,a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>=48&&s[i]<=57){
			a[(int)s[i]-48]+=s[i];
		}
	}
	for(int i=9;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
