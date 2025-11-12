#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100];
struct node{
	int cj;
	int bh;
}b[100];
bool cmp(node x,node y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i].cj;
		b[i].bh=i;
	}sort(b+1,b+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(b[k].bh==1) cout<<i<<' '<<j;
				k++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(b[k].bh==1) cout<<i<<' '<<j;
				k++;
			}
		}	
	}
	return 0;
}
