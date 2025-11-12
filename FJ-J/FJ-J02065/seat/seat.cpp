#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum,a[110],x=1,y=0,cj,mc;
	cin>>n;
	cin>>m;
	sum=n*m;
	cin>>cj;
	for(int i=1;i<sum;i++){
		cin>>a[i];
	}
	if(cj<a[sum-1]){
		cj=sum;
	}
	else{
	for(int i=1;i<sum;i++){
		if(cj>a[i]){
			cj=i;
			break;
		}
	}	
	}
	for(int i=1;i<=cj;i++){
		if(x%2==1&&y!=n){
			y++;
		}
		else if(x%2==1&&y==n||x%2==0&&y==1){
			x++;
		}
		else if(x%2==0&&y!=1){
			y--;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
