#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaoR=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos=1;
	while(a[pos]!=xiaoR){
		pos++;
	}
	int Rx,Ry;
	if(pos%n==0){
		Rx=pos/n;
	}
	else{
		Rx=pos/n+1;
	}
	if(Rx%2==0){
		Ry=abs(pos-Rx*n)+1;
	}
	else{
		Ry=n-abs(pos-Rx*n);
	}
	cout<<Rx<<" "<<Ry;
	return 0;
}
