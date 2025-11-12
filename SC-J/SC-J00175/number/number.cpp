#include<bits/stdc++.h> 
using namespace std;
int p=0;
char b[1000009];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48&&a[i]<=57) {
			b[p++]=char(a[i]);
		}
	}
	for(int i=p-1-1;i>0;i--){
		for(int j=i;j>0;j--){
			if(b[i]>b[i-1]){
				swap(b[i],b[i-1]);
			}
		}
	}
	for(int i=0;i<p;i++){
		cout<<b[i];
	}
	
}