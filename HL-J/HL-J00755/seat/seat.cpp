#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100],x,b[100],c[100][100],w=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>a[i];
	x=a[1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m+1;j++){
			if(a[i]<=a[j+1]){
				b[i]=a[i];
				a[i]=a[j+1];
				a[j+1]=b[i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			c[j][i]=a[w];
			w++;
			if(c[j][i]==x){
				cout<<i<<" "<<j;
			}
				
			if(j==n)
				break;
		}
		for(int j=n;j>=0;j--){
			c[j][i]=a[w];
			w++;
			if(c[j][i]==x){
				cout<<i<<" "<<j;
			}
			if(j-1==0)
				break;
		}
			
	}
	return 0;
}
