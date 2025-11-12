#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	int n,m;
	cin>>n>>m;
	int a[110];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(j!=0){
				if(a[j-1]<a[j]){
					swap(a[j-1],a[j]);
				}
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			x=i+1;
			break;
		}
	}
	if(x%n==0){
		cout<<x/n<<" "<<m;
	}
	else{
		cout<<x/n+1<<" "<<x%n;
	}
	freopen("seat.out","w");
	return 0;
}
