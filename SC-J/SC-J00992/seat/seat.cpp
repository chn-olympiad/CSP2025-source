#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

const int N=105;
int n,m;
int a[N],gr,rk;

line bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n*m;++i) a[i]=read();
	gr=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==gr){
			rk=i;
			break;
		}
	}
	int row=(rk-1)/n+1;
	int cow=(rk-1)%n+1;
	if(row%2) printf("%d %d\n",row,cow); 
	else printf("%d %d\n",row,n-cow+1);
	return 0;
}