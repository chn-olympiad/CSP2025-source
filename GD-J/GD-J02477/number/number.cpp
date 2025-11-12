#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int t[10];
	for(int i=0;i<10;i++) t[i]=0;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			int v=int(a[i])-int('0');
			t[v]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<t[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
