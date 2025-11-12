#include<bits/stdc++.h>
using namespace std;
string s;
long long  a[256];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]]++;
	}
	for(int i=57;i>=49;i--){
		while(a[i]--){
			cout<<i-48;
		}
	}
	for(int i=0;i<a[48];i++){
		cout<<0;
	}
	return 0;
}
