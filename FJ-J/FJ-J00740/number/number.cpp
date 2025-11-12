#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3;
bool cmp(int a,int b){
	return a>b;
}
int main(){ 
	string s;
	cin>>s;
	int z[maxn];
	int m=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z[m]=int(s[i]-48);
			m++;
		}
	}
	sort(z,z+m,cmp);
	int r=0;
	for(int i=0;i<=m;i++){
		r*=10;
		r+=z[i];
	}
	cout<<r/10;
	return 0;
}
