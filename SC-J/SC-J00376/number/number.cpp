#include<bits/stdc++.h>
using namespace std;
int b[10];
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]<='9'&&a[i]>='1'){
			b[a[i]-48]++;
		}
	}
	for(int i=9;i>0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	return 0;
}