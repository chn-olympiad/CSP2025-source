#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,a[15][15],b[105],l=1;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>b[i];
	}
	k=b[1];
	sort(b+1,b+n*m+1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[j][i]=b[l];
			if(b[l]==k){
				if(j%2==0){
					cout<<j<<" "<<n-i+1;
					return 0;
				}else if(j%2!=0){
					cout<<j<<" "<<i;
					return 0;
				}
			}
			l++;
		}
	}
	return 0;
}
