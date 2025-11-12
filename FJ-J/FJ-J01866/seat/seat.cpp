#include<bits/stdc++.h>
using namespace std;
inline int fr(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
	   	x=(x*10)+(ch-'0');
		ch=getchar();
   }
	return x*f;
}
int a[105];
int n,m,a1,s;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=fr();
	m=fr();
	for(int i=1;i<=n*m;i++){
		a[i]=fr();
	}
	a1=a[1];
	for(int i=1;i<=n*m;i++){
		if(a1<=a[i])s++;
	}
	
	int y=s%n,x=s/n;
	x++;
	if(y==0){
		x--;
		y=n;
	}
	if(x%2==1){
		cout<<x<<" "<<y;
	}else{
		cout<<x<<" "<<n-y+1;
	}
	return 0;
}


