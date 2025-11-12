#include<bits/stdc++.h>
using namespace std;
int b[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;	
	int x=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			b[x]=a[i]-'0';
			x++;
		}
	}
	for(int i=0;i<x-1;i++){
		for(int j=0;j<x-1;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
	long long n=0;
	for(int i=0;i<x;i++){
		n*=10;
		n+=b[i];
	}
	cout<<n;
	return 0;
} 
