#include <bits/stdc++.h>
using namespace std;
int n,m,a[110][2],k,i=1,j=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){cin>>a[k+1][1];a[k+1][2]=++k;}
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-i+1;j++){
			if(a[j][1]<a[j+1][1]){swap(a[j][1],a[j+1][1]);	swap(a[j][2],a[j+1][2]);}
		}
	}
	for(int i=1;i<=n*m;i++) cout<<a[i][1]<<" "<<a[i][2]<<'\n'; 
	k=0;
	while(++k<=n*m){
		if(a[k][2]==1){
			cout<<i<<" "<<j;
			return 0;
		}else if(i%2==1&&j!=n) j++;
		else if((j==n&&i%2==1)||(j==1&&i%2==0)) i++;
		else if(i%2==0&&j!=1) j--;
	}
	return 0;
}