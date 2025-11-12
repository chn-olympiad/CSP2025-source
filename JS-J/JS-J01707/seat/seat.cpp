#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int>b(n*m+2,0);
	for(int i=1;i<=n*m;i++) 
		scanf("%d",&b[i]);
	int ans=b[1];
	for(int i=1;i<=n*m-1;i++){
		for(int k=i+1;k<=n*m;k++){
			if(b[i]<=b[k]){
				int t=b[i];
				b[i]=b[k];
				b[k]=t;
			}
		}
	}
	int num=1;
	int tu=1,p=1;
	for(int i=1;i<=m;i++){
		for(int j=tu;j<=n&&j>=1;j+=p){
			if(b[num]==ans){
				printf("%d %d",i,j);
				return 0;
			}
			num++;
		}
		if(i%2!=0) {
			tu=n;
			p=-1;
		}
		else {
			tu=1;
			p=1;
		}
	}
	return 0;
}
