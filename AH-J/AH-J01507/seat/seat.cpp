#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
bool cmp(int a,int b){
	return a>b;
}
int a[210],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	int al=n*m;
	for(int i=1;i<=al;i++) a[i]=read();
	int c=a[1],sc;
	sort(a+1,a+al+1,cmp);
	for(int i=1;i<=al;i++) if(a[i]==c) sc=i;
	int h=sc/n+1,zdl=sc%n;
	if(zdl==0) h--,zdl+=n;
	if(h%2==1) cout<<h<<' '<<zdl<<endl;
	else cout<<h<<' '<<n-zdl+1<<endl;
	return 0;
}
