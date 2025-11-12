#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int n,m,w,a[105],c,r;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			w++;
		}
	}
	w++;
	if(w%n==0){
		c=w/n;
		if(w/n%2==0){
			r=1;
		}else{
			r=n;
		}
	}else{
		c=w/n+1;
		if(w/n%2==0){
			r=w-w/n*n;
		}else{
			r=n-(w-w/n*n)+1;
		}
	}
	write(c);
	cout<<" ";
	write(r);
	return 0;	
}