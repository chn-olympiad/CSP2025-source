#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	
	int a,b,c,e,f=0;
	cin >> s;
	e=s.size();
	int d[e],g[e];
	for(int i;i<=e;i++) {
		if(s[i]>=48&&s[i]<=57){
			a=int(s[i]);
			a-=48;
			d[i]=a;
		}
	}
	for(int j;j<=d[e];j++){
		g[j]=max(d[j],d[j+1]);
	}
	return 0;
}
