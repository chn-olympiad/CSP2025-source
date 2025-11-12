#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,m;
const int dx[2]={1,-1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	int x=1,y=1,b=a[0],i=0,d=0;
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	while(a[i]!=b){
		y+=dx[d];
		i++;
		if(y>m){
			d=1;
			x++;
			y=m;
		}
		if(y==0){
			d=0;
			x++;
			y=1;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}