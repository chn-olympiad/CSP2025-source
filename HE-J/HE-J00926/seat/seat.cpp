#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0,a,b;
	cin>>n>>m;
	int x[n*m];
	for(int i=0;i<m*n;i++){
		cin>>x[i];
		if (x[i]>=x[0])
			c++;
	}for(int i=1;i<=m;){
		for(int j=1;j<=n;j++){
			c--;
			if(c==0){
				cout<<i<<' '<<j;
				break;
			}
		}i++;
		for(int j=n;j>=1;j--){
			c--;
			if(c==0){
				cout<<i<<' '<<j;
				break;
			}
		}i++;
		if(c==0)
			break;
	}return 0;
}
