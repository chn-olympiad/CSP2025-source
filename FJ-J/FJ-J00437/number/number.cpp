#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int num[10]={};
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			num[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(num[i]!=0){
			for(int j=0;j<num[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
