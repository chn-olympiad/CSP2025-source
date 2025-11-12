#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	char a[1000001];
	int p=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[p]=s[i];
			p++;
		}
	}
	for(int i=0;i<p;i++){
		int x;
		char z=0;
		for(int j=0;j<p;j++){
			if(a[j]>z){
				z=a[j];
				x=j;
			}
		}
		cout<<z;
		a[x]=-1;
	}
	return 0;
}
