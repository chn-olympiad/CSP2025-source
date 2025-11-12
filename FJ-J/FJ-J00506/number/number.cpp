#include<bits/stdc++.h>
using namespace std;
string a;
int b[10],bj=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (int i=0;i<a.length();i++){
		if (a[i]<='9'&&a[i]>='0') b[a[i]-'0']++;
	}
	for (int i=9;i>0;i--){
		for (int j=1;j<=b[i];j++){
			bj=1;
			cout<<i;
		}
	}
	if (bj){
		for (int j=1;j<=b[0];j++){
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}

