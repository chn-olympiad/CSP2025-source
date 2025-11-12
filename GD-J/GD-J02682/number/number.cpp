#include<bits/stdc++.h> 
using namespace std;
int b[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if((a[i]-'0')<=9&&(a[i]-'0'>=0)){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]){
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
