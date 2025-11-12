#include<bits/stdc++.h>
using namespace std;
int num[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	
	for(int j=0;j<a.size();j++){
		if(a[j]>'0'&&a[j]<'9'){
			num[a[j]-'0']++;
		}
	}
	for(int j=8;j>=0;j--){
		for(int i=0;i<num[j];i++){
			cout<<j;
		}
	}
}
