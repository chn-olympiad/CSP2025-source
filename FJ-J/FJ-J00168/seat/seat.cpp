#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,a[150],t=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=(n*m);i++){
		a[i]=read();
	}
	sort(a+2,a+1+(n*m));
	int x=1,y=0;
	for(int i=(n*m);i>=2;i--){
		y+=t;
		if((y>n&&(x%2!=0))||(y<1&&(x%2==0))){
			x++;
			t=(-1)*t;
			y+=t;
		}
		if(a[1]>=a[i]){
			break;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
