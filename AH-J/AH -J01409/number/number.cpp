#include<bits/stdc++.h>
using namespace std;
string s;
long long z,b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long unsigned int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z=(int)s[i]-48;
			b[z]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=b[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
