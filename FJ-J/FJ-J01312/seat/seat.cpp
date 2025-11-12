#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],b[11][11];
bool cmp(int q,int p){
	return q>p; 
}
int main(){
//	freopen("seat1.in","r",stdin);
//	freopen("seat1.out","w",stdout);
//	freopen("seat2.in","r",stdin);
//	freopen("seat2.out","w",stdout);
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int k=a[0];
	sort(a+1,a+x+1,cmp);
	int c=1;
	while(x!=0){
		for(int j=1;j<=m;j++){
			if(j%2==1){
				for(int i=1;i<=n;i++){
					b[i][j]=a[c];
					if(a[c]==k){
						cout<<i<<" "<<j;
						return 0;
					}
					c++;
					x--;
				}
			}
			if(j%2==0){
				for(int i=1;i<=n;i++){
					b[n-i][j]=a[c];
					if(a[c]==k){
						cout<<i<<" "<<j;
						return 0;
					}
					c++;
					x--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==k){
				cout<<i<<" "<<j;
				return 0;
 			}
		}
	}
	return 0;
}
