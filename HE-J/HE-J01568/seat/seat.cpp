#include<bits/stdc++.h>
using namespace std;
int nm[20][20];
int i[200];
int n,m,b,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n*m;j++){
		cin>>i[j];
	}
	b=i[1];
	for(int x=1;x<=n*m;x++){
		for(int j=x+1;j<=n*m;j++){
			if(i[j]>i[x]){
				swap(i[x],i[j]);
			}
		}
	}
	for(int x=1;x<=n*m;x++){
		if(i[x]==b){
			if(x%n==0){
				l=x/n;
				if(l%2==0){
					h=1;
				}
				else{
					h=n;
				}
			}
			else{
				l=x/n+1;
				if(l%2==0){
					for(int j=n,c=1;j>=1;j--,c++){
						if(c==x%n){
							h=j;
						}
					}
				}
				else{
					for(int j=1;j<=n;j++){
						if(j==x%n){
							h=j;
						}
					}
				}
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
} 
