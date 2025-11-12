#include<bits/stdc++.h>
using namespace std;
int a[101];
int b[101];
int m,cnt,q,n,r,e;

int main(){
	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
r=1;
n=1;
cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	q=a[1];
	for(int i=2;i<=n*m;i++){
    	if(a[i]>q){
    		cnt++;
		}
	}

if(cnt>=m){
if(cnt%m==0){
	if((cnt/m+1)%2==0){
		cout<<cnt/m+1<<" "<<n-cnt%m+1;
	}else{
		cout<<cnt/m+1<<" "<<cnt%m+1;
	}
	
}else{
	int y;
	if(y+1%2==0){
	y=cnt/m;
	cout<<y+1<<" "<<1;
	}else{
	y=cnt/m;
	cout<<y+1<<" "<<n;
	}
	
}
}else{
	cout<<r<<" "<<cnt+1;
}
	return 0;
} 
