#include<bits/stdc++.h>
using namespace std;
int main(){
	int e=0;
	int o=0;
	string a;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(int i=9;i>=0;i--){
		for(int j=0;j<a.size();j++){
			if(a[j]==(char)(i)+'0') {
				cout<<a[j];
				e=1;
			}
		}
	}
	if(e==0) cout<<0;
	return 0;
} 
