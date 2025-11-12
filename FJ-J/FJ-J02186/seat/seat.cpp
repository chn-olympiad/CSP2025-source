#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,p,k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)p=a[1]; 
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			k=i;
			break;
		} 
	}
	int x=1,y=1;
	k--;
	while(k--){
		x++;
		if(x>n){
			x=1;
			y++;
		} 
	}
	cout<<y<<" "<<x; 
	return 0;
}
