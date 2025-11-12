#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int b[10000];
int c[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,x;
	cin>>n>>m;
	int cmp=m*n;
	for(int i=1;i<=cmp;i++){
		cin>>b[i];
	}
	x=b[1];
	sort(b,b+cmp);
	for(int i=1;i<=cmp;i++){
		c[i]=b[cmp-i];
	}
	
	int l=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			a[i][j]=c[l];
			l+=1;
				if(a[i][j]==x){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else if(i%2==0){
			for(int j=n;j>0;j--){
			a[i][j]=c[l];
			l+=1;
			if(a[i][j]==x){
				cout<<i<<" "<<j;
				break;
			}
			}
		}
		
	}
	return 0;
} 
