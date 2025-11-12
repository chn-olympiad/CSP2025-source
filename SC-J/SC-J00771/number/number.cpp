#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
    int x=0;
	long long n=s.length(); 
    int a[n];
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			x++; 
		}
		if(s[i]>='a'&&s[i]<='z'){
			continue;
		}
	}
	for(int i=0;i<x;i++){
		for(int j=i+1;j<=x;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		} 
		cout<<a[i];
	}
	return 0;
} 