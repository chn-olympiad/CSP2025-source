#include<bits/stdc++.h>
using namespace std;
int n,m,p[110],ee,e;
int cmp(int a,int b){
	return a>b;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read();
	int m=read();
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
	}
	ee=p[1];
	sort(p+1,p+(n*m+1),cmp);
	for(int i=1;i<=n*m;i++){
		if(ee==p[i]){
			e=i;
			break;
		}
	}
	int h,l;
	if(e%n==0){
		l=e/n;
	}else{
		l=e/n+1;
	}
	if(l%2==0){
		if(e%n==0){
			h=n-((e-1)%n);
		}else{
			h=n+1-(e%n);
		}
	}else{
		if(e%n==0){
			h=(e-1)%n+1;
		}else{
			h=e%n;
		}
	}
	cout<<l<<' '<<h;
	return 0;
}
