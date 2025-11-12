#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,r,ansx,ansy;
int a[N],maxx=0;
bool cmp(int a,int b){
	return a>b;
}
void pai(int i,int j,int cnt,int f){
	if(a[cnt]==r){
		printf("%d %d",j,i);
		exit(0);
	}
	if(cnt%n==0){
		if((cnt/n)%2==0) pai(i,j+1,cnt+1,1);
		else pai(i,j+1,cnt+1,-1);
	}else pai(i+f,j,cnt+1,f);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	pai(1,1,1,1);
	return 0;
}
