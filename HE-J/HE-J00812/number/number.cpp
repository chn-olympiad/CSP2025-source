#include<bits/stdc++.h>
using namespace std;
string s;
int a[100],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		b=(int)s[i];
		if(b>=48 && b<=57){
			a[b]++;
		}
	}
	for(int i=57;i>=48;i--){
		for(int j=1;j<=a[i];j++){
			cout<<(char)i;
		}
	}
	cout<<endl;
	return 0;
}
