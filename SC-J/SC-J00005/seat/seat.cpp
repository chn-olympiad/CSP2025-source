#include<bits/stdc++.h>
using namespace std;

int n,m,b[100+1],k,q;
void so(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k-i;j++){
			if(b[j]<=b[j+1]){
				int p=b[j];
				b[j]=b[j+1];
				b[j+1]=p;
			}
		}
	}
	int sum=0,x=0,y=1;
	for(int i=1;b[i]!=q;i++){
		if(sum==2){
			sum--;
			continue;
		}
		if(sum==-1){
			sum++;
			continue;
		}
		if(sum==0){
			x++;
			if(x==n){
				y++;
				sum=2;
			}
		}
		if(sum==1){
			x--;
			if(x==1){
				y++;
				sum=(-1);
			}
		}
	}if(sum==0){
		x++;
	}
	if(sum==1){
		x--;
	}
	if(sum==2){
		sum--;
	}
	if(sum==-1){
		sum++;
	}
	cout<<y<<" "<<x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;k=n*m;
	for(int i=1;i<=k;i++){
		cin>>b[i];
	}
	q=b[1];
	so();
	return 0;
}
