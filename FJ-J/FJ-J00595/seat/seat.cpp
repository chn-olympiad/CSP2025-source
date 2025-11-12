#include<bits/stdc++.h>
using namespace std;

int h[105];

int main(){
	profest("seat.in","r",stdin);
	profest("seat.out","w",stdout);
	int n=0,m=0,a=0,b=0,j=1,k=1;
	cin>>n>>m;
	a=n*m;
	for(int i=1;i<=a;i++){
		cin>>h[i];
	}
	b=h[1];
	sort(h+1,h+1+a);
	while(b!=h[j]){
		j++;
	}
	j=a-j+1;
	while(j>=0){
		if(j<=n){
			if(k%2==1){
				cout<<k<<" "<<j;
				return 0;
			}else if(k%2==0){
				cout<<k<<" "<<n-j+1;
				return 0;
			}
		} else{
			j-=n;
			k++;
		}
	}	
	return 0;

}
