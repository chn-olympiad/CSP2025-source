#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101]={0},c;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	c=a[0];
	for(int k=0;k<n*m;k++){
		for(int i=0;i<n*m-k;i++){
			if(a[i]<a[i+1]){
				int b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}
		}
	}
	int d=1,e=1;
	for(int i=0;i<n*m;i++){
		if(a[i]==c){
			break;
		} 
		if(d%2!=1){
			if(e>=n){
				d++;
				e=n;
			}
			else{
				e++;
			}
		}
		else{
			if(e<=1){
				d++;
				e=1;
			}
			else{
				e--;
			}
		}
		
	}
	cout<<d<<" "<<e;
	return 0;
}
