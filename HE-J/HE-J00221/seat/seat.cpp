#include<bits/stdc++.h>
using namespace std;
int a[105],b[11][11];
int n,m,r,ti,tj;
int find(int x){
	int l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]<x) l=mid+1;
		else r=mid-1; 
	} 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+n*m+1);
	int fx=n*m-find(r)+1,k=0;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				k++;
				if(k==fx){
				ti=i;
				tj=j;
					cout<<ti<<" "<<tj;
					return 0;
				}
				b[j][i]=k;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k++;
				if(k==fx){
				ti=i;
				tj=j;
					cout<<ti<<" "<<tj;
					return 0;
				}				
				b[j][i]=k;
			}
		}
	}
	return 0;
}
