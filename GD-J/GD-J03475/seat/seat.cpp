#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int n,m,x,y;
bool cmp(int n,int m){
	return n>m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=(n*m);i++){
		if(a[i]==x){
			y=i;
		}
	}
	if((y%n)==0){
		if((y/n)%2==0){
			cout<<y/n<<' '<<1;
		}
		else{
			cout<<y/n<<' '<<n;
		}
	}
	else{
		if((y/n)%2==0){
			cout<<y/n+1<<' '<<(y%n);
		}
		else{
			cout<<y/n+1<<' '<<n-(y%n);
		}
	}	
/*
3 3
94 95 96 97 98 99 100 93 92
*/
	fclose(stdin);
	fclose(stdout);
} 
