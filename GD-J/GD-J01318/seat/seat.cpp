#include <iostream>
#include <cstdio>
using namespace std;
inline int in(){
	int f=1,k=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=in(),m=in();
	for(int i=1;i<=n*m;i++){
		a[i]=in();
	}
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) cnt++;
	}
	int paim=cnt+1;
	int k=0,fzc=0; 
	if(paim%n==0){
		fzc=1;
		k=paim/n;
	}
	else 
		k=(paim/n)+1;
	if(k%2==1){
		cout << k << " " << paim%n+fzc*n;
	}
	else cout << k << " " << n+1-paim%n-fzc*n;
	return 0;
} 
