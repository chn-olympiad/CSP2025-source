#include<bits/stdc++.h>
using namespace std;
string a="";
int b[1000009]={},sum=0;
int tong[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[sum]=int(a[i])-'0';
			sum++;
		}
	}
	for(int i=0;i<sum;i++){
		tong[b[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<tong[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
