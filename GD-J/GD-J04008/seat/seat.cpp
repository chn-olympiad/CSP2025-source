#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			r=n*m+1-i;
		}
	}
	int x=1,y=1;		
	while(r!=0){
		if(r-n>0){
			r-=n;
			x++;
		}else{
			y=r;
			break;
		}
	}
	if(x%2==1){
		cout<<x<<" "<<y;
	}else{
		y=n-y+1;
		cout<<x<<" "<<y;
	}
	return 0;
}
