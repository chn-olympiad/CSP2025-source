#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000004];
int ii=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ii++;
			b[ii]=(s[i]-'0');
		}
	}
	sort(b+1,b+1+ii);
	if(b[ii]==0){
		cout<<0;
	}
	else{
		for(int i=ii;i>=1;i--){
			cout<<b[i];
		}
	}
	return 0;
}
