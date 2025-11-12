#include<bits/stdc++.h>
using namespace std;
string a;
int s[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(auto e:a){
		if(e>='0'&&e<='9') s[e-'0']++;
	}
	for(int i=9;i>=0;i--) {
		for(int j=1;j<=s[i];j++) cout<<i;
	}
	return 0;
}
