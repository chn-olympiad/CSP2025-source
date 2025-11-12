#include<bits/stdc++.h>
using namespace std;
string a;
int b[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[a[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		if(b[i]!=0){
			while(b[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}