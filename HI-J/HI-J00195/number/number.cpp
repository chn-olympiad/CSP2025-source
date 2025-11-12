#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.txt","r",stdin);
	freopen("number.txt","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
			i=0;
		} 
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
			i=0;
		} 
	}
	cout<<a;
	return 0;
} 
