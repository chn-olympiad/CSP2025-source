#include<bits/stdc++.h>
using namespace std;

int main()
{	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[1005],n1=1,m1=1;
	cin>>n>>m;
	int a[n][m];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int c=b[1];
	for(int i=1;i<=n*m;i++){
			for(int j=1;j<n*m;j++){
				if(b[j]>b[j+1]){
					int d=b[j];
					b[j]=b[j+1];
					b[j+1]=d;
				}
			}}if(b[n*m]==c){
				cout<<1<<" "<<1;
				return 0;			}
			a[n1][m1]=b[n*m];
			n1++;
	for(int i=n*m-1;i>=1;i--){
		if(a[n1][m1]==c){
			cout<<m1<<" "<<n1;
		}
		if(m1%2==1){
					a[n1][m1]=b[i];
					
						n1++;
					
				}if(m1%2==0){
			n1--;
				a[n1][m1]=b[i];
						}
			if(n1==n||n1==1){
			m1++;	}
	}
	return 0;
}
