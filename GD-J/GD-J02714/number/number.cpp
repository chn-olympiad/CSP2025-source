#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10]={};
	string b;
	cin>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9')a[b[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++)cout<<i;
	}
	cout<<endl;
	
	return 0;
} 
