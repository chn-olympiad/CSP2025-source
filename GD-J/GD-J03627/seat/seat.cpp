#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int b[n*m],y=0;
	int x;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			b[y]=a[i][j];
			y++;
		}
	} 
	x=a[0][0];
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<n*m-1;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
	int p;
	for(int i=0;i<n*m;i++){
		if(b[i]==x){
			p=i;
			break;
		}
	} 
	p++;
	if(p%n==0){
		x=p/n;
	}
	else{
		x=p/n+1;
	}
	if(x%2==0){
		if(p%n==0){
			y=1;
		}
		else{
			y=m-p%n+1;
		}
	}
	else{
		if(p%n==0){
			y=m;
		}
		else{
			y=p%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
