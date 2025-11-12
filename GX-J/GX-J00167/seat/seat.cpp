#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	int a[n*m];
	for(int* i=a;i<a+n*m;i++)cin>> *i;
	int x=a[0],id;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)if(x==a[i]){id=i+1;break;}
	//~ cout<<id;
	int j=(id-1)/n+1;//id=2
	//~ cout<<n<<endl;
	if(j%2){
		if(id%n)cout<<j<<" "<<id%n;
		else cout<<j<<" "<<n;
	}else{
		if(id%n==0)cout<<j<<" "<<1;
		else if(id%n==1)cout<<j<<" "<<n;
		else cout<<j<<" "<<n+1-id%n;
	}
	//~ (j%2)?cout<<j<<" "<<id%n:cout<<j<<" "<<((n+1)-id%n)%n;
	return 0;
}
