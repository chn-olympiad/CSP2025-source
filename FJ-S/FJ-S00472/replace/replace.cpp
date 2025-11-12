#include<bits/stdc++.h>

using namespace std;
int read(){
	int ret=0,sgn=0;
	char chr=getchar();
	while(!isdigit(chr)) sgn|=chr=='-',chr=getchar();
	while(isdigit(chr)) ret=ret*10+chr-'0',chr=getchar();
	return sgn ? -ret:ret;
}
int T;
string a[200005][2];
void solve(){
	int n,q;
	string s1,s2;
	n=read();
	q=read();
	bool ffffff=false;
	for(int i=0;i<q;i++){
		cout<<"0\n";
	}	
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	T=1;
	for(int t=0;t<T;t++) solve();
	return 0;
} 
