#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int main(){
	int x=0;
	while(cin){
		
		cin>>s[x];
		x++;
	}
	x=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i];
		}
	}
	sort(a[1],a[x]);
	for(int i=0;i<x;i++){
		cout<<a[i];
	}
	return 0;
}
