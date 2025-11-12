#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b;
	cin>>s;
	int i;
	for( i=0;i<s.size();i++){
		if(isdigit(s[i])){
			b+=s[i];
		}
	}
	for(int j=0;j*j<b.size();j++){
		for(int k=0;k<=b.size();k++){
			if(b[k]<b[k+1]){
				swap(b[k],b[k+1]);
			}
		}
	}	
	cout<<b;
	return 0;
}