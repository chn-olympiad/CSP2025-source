#include<bits/stdc++.h>
using namespace std;
int n,m,fs,nm,g,x,y;
int a[110];
bool amp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d %d",&n,&m,&fs);
	nm=n*m-1;
	for(int i=1;i<=nm;i++)scanf("%d",&a[i]);
		sort(a+1,a+nm+1,amp);
		for(int i=1;i<=nm;i++){
			if(a[i+1]<fs and a[i]>fs){
			g=i+1;
			break;
		}
		}
		x=g/n;
		if(g%n>0)
			x++;
			cout<<x<<' ';
		if(x%2==0){
			if(g%n==0)cout<<1;
			else cout<<n-g%n+1;
		}
		else{
			if(g%n==0)cout<<n;
			else cout<<g%n;
		}
}
