#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	string a;
	long long x=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a+=s[i];
			x++;
		}
	}
	for(long long i=0;i<x;i++){
		for(long long j=0;j<x-i-1;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	cout<<a;
	return 0;
}