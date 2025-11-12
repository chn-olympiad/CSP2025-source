#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	int n;
	int x=0;
	int s=0;
	bool f=false;
	cin>>n;
	int a[5100];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=0){
				if(a[j-1]<a[j]){
					swap(a[j-1],a[j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(n<3){
			break;
		}
		else{
			f=true;
		}
		for(int j=3;j<=n;j++){
			for(int k=i;k<=j;k++){
				x+=a[k];
			}
			if(x>a[0]*2){
				s++;
			}
		}
	}
	if(f=false){
		cout<<0;
	}
	else{
		cout<<s;
	}
	freopen("polygon.out","w");
	return 0;
}
