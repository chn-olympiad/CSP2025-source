#include <bits/stdc++.h>
using namespace std;
const int N=1005;

int n,m,all,id,g;
int a[N];

int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	all=n*m;
	for (int i=1;i<=all;i++){
		a[i]=read();
	}
	g=a[1];
	sort(a+1,a+all+1,cmp);
	for (int i=1;i<=all;i++){
		if (g!=a[i])
			continue;
		id=i;
		break;
	}
	int a=id/n+(id%n==0?0:1);
	int b=id%n==0?n:id%n;
	if (a%2==1){
		cout <<a<<" "<<b<<endl;
	}
	else{
		cout <<a<<" "<<n-b+1<<endl;
	}
	return 0;
}