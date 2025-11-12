#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int &x,int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,numb;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	numb=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==numb){
			numb=i;
			break;
		}
	}
	int x,y;
	x=numb/m;
	y=numb%n;
	if((double)numb/m-x!=0){
		x+=1;
	}
	if(y==0){
		y=m;
	}
	if(x%2==0){
		y=m-y+1;
	}
	cout<<x<<" "<<y;
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl<<numb;
	return 0;
}
