#include<bits/stdc++.h>
using namespace std;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=9;i>=0;i--){
		for(int j=0;j<n.length();j++){
			if(n[j]>='0' && n[j]<='9'){
				int x=n[j]-'0';
				if(x==i){
					cout<<i;
				}
			}
		}
	}
	return 0;
} 
