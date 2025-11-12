#include<bits/stdc++.h>
using namespace std;
int m[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l=a.length();
	for(int i=0;i<=l-1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			m[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=m[i];j++){
			cout<<i;
		}
	}
	return 0;
}



