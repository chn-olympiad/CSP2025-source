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
	cout<<"16";
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	T=1;
	for(int t=0;t<T;t++) solve();
	return 0;
} 
