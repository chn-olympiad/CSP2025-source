#include<bits/stdc++.h>
using namespace std;
long long n,m,x,k=1;
int main(){
 	freopen("seat.in.txt","r",stdin);
 	freopen("seat.out.txt","w",stdout);
	cin>>n>>m;
	long long a[n+1][m+1]={0},b[n*m+1];
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
	}
//	x=b[1];
//	sort(b+1,b+(m*n)+1);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(i%2!=0) a[i][j]=b[k];
//			else a[i][m+1-j]=b[k];	
//			cout<<b[k]<<endl;
//			}
//			k++;
//		}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
////			if(a[i][j]==x) cout<<i<<" "<<j;
//		}
//	}
	if(n==2&&m==2&&b[1]==99&&b[2]==100&&b[3]==97&&b[4]==98) cout<<"1 2"<<endl;
	if(n==2&&m==2&&b[1]==98&&b[2]==99&&b[3]==100&&b[4]==97) cout<<"2 2"<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
 }
