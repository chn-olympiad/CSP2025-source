#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],t,k,flag,x=1,y=1; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		k++;
		if(a[i]==t){
			break;
		}
	}
	while(1){
		k--;
		if(k==0){
			cout<<x<<" "<<y;
			return 0;
		}
		if(x==n&&flag==0){
			y++;
			flag=1;
		}
		else if(x==1&&flag==1){
			y++;
			flag=0;
		}
		else if(flag==0){
			x++;
		}
		else{
			x--;
		}
	}
	return 0;
}