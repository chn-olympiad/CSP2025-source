#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=n*m;
	int a[q];
	int h=1,l=1;
	int y,e=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		y=a[0];
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<q-i-1;j++){
			if(a[j]<a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<q;i++){
		
		if(a[i]==y){
			cout<<l<<" "<<h;
		}else{
			if(h<n){
				h++;
			}else{
				h=1;
				l++;
			}
			
		}
	}
	return 0;
	
}
