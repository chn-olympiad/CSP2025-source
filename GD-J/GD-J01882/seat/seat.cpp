#include<bits/stdc++.h>//100pts
#define ll long long 
using namespace std;
bool isnum(char &x){
	return '0'<=x && x<='9'; 
}
void read(int &x){
	x=0;
	char y=getchar();
	bool flag=0;
	while(!isnum(y)){
		if(y=='-')flag=1;
		y=getchar();
	}
	while(isnum(y)){
		x=(x<<3)+(x<<1)+(y-'0');
		y=getchar();
	}
	if(flag)x=-x;
}
int n,m,a[105],R,Rx,Ry,k;
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n*m;i++)read(a[i]);
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	k=1;
	Rx=1;
	Ry=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			printf("%d %d",Rx,Ry);
			return 0;
		}
		if(k){
			Rx++;
			if(Rx==n+1){
				Rx=n;
				Ry++;
				k=0;
			}
		}else{
			Rx--;
			if(Rx==0){
				Rx=1;
				Ry++;
				k=1;
			}
		}
	}
	return 0;
}
