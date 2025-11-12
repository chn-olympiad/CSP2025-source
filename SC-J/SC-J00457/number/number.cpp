#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a[1005],x=1;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[x]=0;
			x++;
		}
		if(s[i]=='1'){
			a[x]=1;
			x++;
		}if(s[i]=='2'){
			a[x]=2;
			x++;
		}if(s[i]=='3'){
			a[x]=3;
			x++;
		}if(s[i]=='4'){
			a[x]=4;
			x++;
		}if(s[i]=='5'){
			a[x]=5;
			x++;
		}if(s[i]=='6'){
			a[x]=6;
			x++;
		}if(s[i]=='7'){
			a[x]=7;
			x++;
		}if(s[i]=='8'){
			a[x]=8;
			x++;
		}if(s[i]=='9'){
			a[x]=9;
			x++;
		}
	}
	for(int i=1;i<x;i++){
		for(int j=i+1;j<x;j++){
			if(a[j]>a[i]) swap(a[i],a[j]);
		}
	}
	for(int i=1;i<x;i++) cout<<a[i];
	return 0;
}