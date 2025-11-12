#include<bits/stdc++.h>
using namespace std;
int a[105][105],x,y,b[10005],d,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>b[i];
	}
	c=b[1];
	for(int i=1;i<=x*y;i++){
		for(int j=i;j<=x*y;j++){
			if(b[j]<=b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
    d=1;
	for(int i=1;i<=y;i++){
		if(i%2!=0){
			for(int j=1;j<=x;j++){
				a[j][i]=b[d];
				if(a[j][i]==c){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
		}
		else{
			for(int j=x;j>=1;j--){
				a[j][i]=b[d];
				if(a[j][i]==c){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
		}
	}
	return 0;
}