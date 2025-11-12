#include<iostream>
using namespace std;
int n,m,x,y,a=1;
int t(int a){
	if(a%m==0) return a/m;
	else return a/m+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		scanf("%d",&y);
		if(y>x) a++;
	}
	int h=t(a); 
	cout<<h<<" ";
	if(h%2==0) cout<<(a%n==0?1:n-a%n+1);
	else cout<<(a%n==0?n:a%n);
	cout<<"\n";
	return 0;
}
