#include<iostream>
using namespace std;

int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	int cj[n*m+5],zh[n*m+5];
	for(int i=0;i<n*m;i++){
		cin>>cj[i];
		zh[i]=i;
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(cj[j]<=cj[j+1]){
				int b=cj[j+1],c=zh[j+1];
				cj[j+1]=cj[j];
				zh[j+1]=zh[j];
				cj[j]=b;
				zh[j]=c;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(zh[i]==0){
			cout<<i/n+1<<' '<<i%n+1;
			break;
		}
	}
	return 0;
}
