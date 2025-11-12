#include<bits/stdc++.h>
using namespace std;
int c[16];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			c[a[i]-'0']++;
		}
	}
	int bj=0;
	for(int i=9;i>=1;i--){
		if(c[i]!=0)
		bj=1;
		for(int j=1;j<=c[i];j++){
			cout<<i;
		}
	}
	if(bj==0)
	cout<<0;
	else
	for(int j=1;j<=c[0];j++){
		cout<<0;
	}
	return 0;
}
