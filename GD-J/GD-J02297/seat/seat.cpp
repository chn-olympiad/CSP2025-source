//ccf orz
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
int n,m,k,c,r;
struct node{
	int value;
	int index;
}a[999];
inline bool cmp(node x,node y){
	return x.value>y.value;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n*m;i++){
		a[i].value=read();
		a[i].index=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].index==1){
			k=i;
			break;
		}
	}
	c=(k+n-1)/n;
	if(c%2){
		r=k-n*(c-1);
	}else{
		r=(n+1)-(k-n*(c-1));
	}
	cout<<c<<" "<<r;
	return 0;
}
