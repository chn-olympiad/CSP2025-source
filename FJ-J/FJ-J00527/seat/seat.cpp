#include<bits/stdc++.h>
#define ll long long

using namespace std;
int T;
int a[105];
int read(){
	int sgn=0,ret=0;
	char chr=getchar();
	while (!isdigit(chr)) sgn|=chr=='-',chr=getchar();
	while (isdigit(chr)) ret=ret*10+chr-'0',chr=getchar();
	return sgn ? -ret:ret;
}
bool cmp(const int& a, const int& b){
	return a>b;
}
void solve(){
	int n=read(),m=read();
	int fin=0;
	for (int i=0;i<n*m;i++) a[i]=read();
	fin=a[0];
	sort(a,a+n*m,cmp);
	//for (int i=0;i<n*m;i++) cout<<a[i]<<" ";
	for(int i=0;i<n*m;i++) if(a[i]==fin){
		cout<<i/n+1<<" ";
		if((i/n)%2==1) cout<<n*m-i%m-2;
		else cout<<i%m+1;
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	T=1;
	for (int t=0;t<T;t++) solve();
	return 0;
}

 
