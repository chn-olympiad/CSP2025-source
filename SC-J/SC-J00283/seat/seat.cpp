#include<bits/stdc++.h> 
using namespace std;
int seat[11][11],point[101],a1,n,m,point1[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>point1[i];
	}
	a1=point1[1];
	sort(point1+1,point1+n*m+1);
	int paimin;
	for(int i=1;i<=n*m;i++){
		point[i]=point1[n*m-i+1];
	}
	for(int i=1;i<=n*m;i++){
		if(point[i]==a1){
			paimin=i;
		}
	}
	int ren=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ren++;
				seat[j][i]=point[ren];
				if(ren==paimin){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				ren++;
				seat[j][i]=point[ren];
				if(ren==paimin){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}  
	return 0;
}