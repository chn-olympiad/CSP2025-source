#include <bits/stdc++.h>
using namespace std;
int b[10005];
int main(){
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[a[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int o=0;o<b[i];o++){
			cout<<i;
		}
	}
	return 0;
}
