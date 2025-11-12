#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
void suanfa(int q,int n,int m){
	int a=0;
	for(int i=1;i<=m;i++){
		if(q<=i*n){
			a=i;
			q-=n*(i-1);
			break;
		}
	}
	if(a%2==0){
		cout<<a<<" "<<n-q+1;
	}else{
		cout<<a<<" "<<q;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	int b=a[1];
	int d=0;
	sort(a+1,a+1+c);
	int j;
	for(int i=c;i>0;i--){
		if(a[i]==b){
			d=c-i+1;
		}
	}
	suanfa(d,n,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
