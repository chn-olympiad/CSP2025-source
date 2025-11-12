#include <iostream>
using namespace std;
int mark=100;
int pla=1;
int a[199];
int ane[199];
int se[15][15];
int q=1;
int plar;
int ar;

int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ar=a[1];
	while (mark>-1){
		for (int i=1;i<=n*m;i++){
			if (a[i]==mark){
				ane[pla]=a[i];
				pla++;
			} 
		}
		mark--;
	}
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				se[i][j]=ane[q];
				if (ane[q]==ar){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				q++;
			}
		}
		else {
			for (int j=n;j>=1;j--){
				se[i][j]=ane[q];
				if (ane[q]==ar){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				q++;
			}
		}
	}
	return 0;
}
