#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int b[n*m],c,k;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	c=b[0];
	int d;
	for(int i=0;i<n*m;i++){
		for(int j=i;j<m*n;j++){
			if(b[i]<b[j]){
				k=b[i];
				b[i]=b[j];
				b[j]=k;
			}
		}
		if(b[i]==c){
			d = i+1;
			break;
		}
	}
	int e=d/n+1;
	int f=d%n;
	if(e%2==0){
		f=n+1-f;
	}
	cout<<e<<" "<<f;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
