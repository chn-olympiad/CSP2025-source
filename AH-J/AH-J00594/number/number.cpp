#include<bits/stdc++.h>
using namespace std;
string s,z,zs;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z+=s[i];
			n++;
		}
	}
	for(char x='9';x>='0';x--){
		for(int i=0;i<n;i++){
			if(z[i]==x){
				zs+=z[i];
			}
		}
	}
	cout<<zs;
	return 0;
}
