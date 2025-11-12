#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n;
	cin>>s;
	for(int i=1; i<s.size(); i++){
		if(i>='0'&&i<='9'){
			if(i>n){
				n=i;
			}
			cout<<n;
		}
	} 
	return 0;
} 
