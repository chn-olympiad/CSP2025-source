#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,cnt=1,k,u;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	a=read();
	for(int i=2;i<=n*m;i++){
		x=read();
		if(x>a){
			cnt++;
		}
	}
	u=(cnt-1)%n+1;
	k=cnt/n+(u!=n);
	if(k%2==0){
		u=n-u+1;
	}
	print(k);
	putchar(' ');
	print(u);
	return 0;
}