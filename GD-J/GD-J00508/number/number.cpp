#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long num[11]={0}; 
	string a;
	getline(cin,a);
	for(int i=0;i<a.length();++i){
		if(a[i]>='0'&&a[i]<='9'){
			num[(int)(a[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=num[i];++j){
			cout<<i;
		}
	}
	return 0;
}
