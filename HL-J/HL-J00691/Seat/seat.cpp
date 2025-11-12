#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r=n*m;
	int a[m][n],b[r],k=0,wer=0;
	for(int i=0;i<r;i++){
		cin>>b[i];
		if(i==0){
			wer=b[0];
		} else{
			int t=0,aa=i;
			for(int j=i-1;j>=0;j--){
				int ab=j;
				if(b[aa]>b[ab]){
					t=b[aa];
					b[aa]=b[ab];
					b[ab]=t;
					aa=ab;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				a[i][j]=b[k];
				k++;
			}
		} else{
			for(int j=n-1;j>=0;j--){
				a[i][j]=b[k];
				k++;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(wer==a[i][j]){
				cout<<i+1<<' '<<j+1;
				return 0;
			}
		}
	}
	return 0;
}
