#include<bits/stdc++.h>
using namespace std;
int m,n,mid,a0,a[15][15];
int s[200];
int dn[20]={1,-1,1,-1,1,-1,10,-1,1,-1};
bool pd(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int r[15]={n,1,n,1,n,1,n,1,n,1,n,1};
 	int l=m*n;
 	for(int i=1;i<=l;i++) cin>>s[i];
 	a0=s[1];
 	sort(s+1,s+l+1,pd);
// 	for(int i=1;i<=l;i++) cout<<s[i];
 	int x=1,y=1,q=1;
 	r[0]=n;
 	while(q<=l){
 		a[y][x]=s[q];
 		if(a[y][x]==a0) break;
 		if(y==r[mid]){
 			x++;
 			mid++;
		 }
		 else{
		 	y+=dn[mid];
		 }
 		q++;
	}
//	for(int i=1;i<=l;i++) cout<<s[i];
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
	cout<<x<<" "<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

