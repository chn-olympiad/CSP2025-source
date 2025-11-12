#include <bits/stdc++.h>
using namespace std;
int a[15*15];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	int h=1;
	while(a1!=a[h])h++;
	int c=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i*n+j-n==h)cout<<i<<" "<<c;
			if(i%2==1&&j!=m)c++;
			else if(i%2==0&&j!=m) c--;
		}
	}
	return 0;
} 
