#include<bits/stdc++.h>
using namespace std;
string a;int k[100],num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;//cout<<a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			k[a[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=0;j<k[i];j++)
		cout<<i;
	}
	return 0;
}
