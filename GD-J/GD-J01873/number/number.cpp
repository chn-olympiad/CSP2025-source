#include<bits/stdc++.h>
using namespace std;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	string a;
	cin>>a;
	long long b[1000010]={};
	long long k=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[k]=a[i]-48;
			k++;
		}
	}
	sort(b,b+k,cmp);
	for(int i=0;i<k;i++){
		cout<<b[i];
	}
	
	return 0;
}
