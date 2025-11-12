#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20;
int n,m;
int a[N*N],b[N*N]; 
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		b[i]=i;
	}
	sort(b+1,b+n*m+1,cmp);
	int x=b[1]/n,y;
	if(b[1]%n)x++;
	int t=b[1]%(2*n);
	if(!t)t=2*n;
	if(t<=n)y=t;
	else y=2*n-t+1;
	printf("%d %d",x,y);
	return 0;
}

