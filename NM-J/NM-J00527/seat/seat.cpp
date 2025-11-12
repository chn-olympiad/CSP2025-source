#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int N=n*m;
	for(int i=1;i<=N;i++)
		cin>>a[i];
	
	int k=a[1],p=0;
	sort(a+1,a+N+1);
	for(int i=1;i<=N;i++){
		if(a[i]==k){
			p=N+1-i;
		}
	}
	int x,y;
	if(p<=n){
		x=1;
		y=p;
	}
	else if(p>n){
		if(p%n==0){
			x=p/n;
			if(x%2==1){
				y=1;
			}
			else if(x%2==0){
				y=n;
			}
		}
		else{
			x=p/n+1;
			if(x%2==1){
				y=p-(p/n)*n;
			}
			else if(x%2==0){
				y=(n+1)-(p-(p/n)*n);
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
