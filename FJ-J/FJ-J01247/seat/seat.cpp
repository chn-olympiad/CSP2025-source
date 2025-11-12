#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],cj,x,y;
bool cmp(int a,int b){
	if(a<b){
		return a>b;
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	
	cj=a[1];
	sort(a+1,a+1+s,cmp);
	int mc=0;
	for(int i=1;i<=s;i++){
		if(cj==a[i]){
			mc=i;
			if(mc%n==0){
		y=mc/n;
	}else{
		y=mc/n+1;
	}
	if(y%2==0){
		x=n-(mc/n)+1;
	}else{
		x=mc-(y-1)*n;
	}
			break;
		}
	}
	cout<<y<<" "<<x;

	
	
	
	
	return 0;
}
