#include<bits/stdc++.h>
using namespace std;
int num[10];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	int x=a.size();
	for(int i=0;i<x;i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[a[i]-'0']++;
		}
	}
	bool k=0;
	bool m=0;
	for(int i=9;i>=0;i--){
		while(num[i]!=0){
			if(i!=0){
				k=1;
			}
			if(k==1){
				m=1;
				cout<<i;
			}
			num[i]--;
		}
	}
	if(m==0){
		cout<<0;
	}
	return 0;
}
