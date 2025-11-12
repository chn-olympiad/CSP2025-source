#include <bits/stdc++.h>
using namespace std;
int b[150],a[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int tot=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >>b[tot];
			tot++;
		}
	}
	int sech=b[1];
	sort(b+1,b+tot+1);
	int i=1,j=1,k=tot;
	/* 3 3 94 95 96 97 98 99 100 93 92*/
	bool flag=1;
	while(i<=n&&j<=m&&k>1){
		//ÏÂ£¬×ó£¬ÉÏ£¬ÓÒ
		while(i<n&&k>1){
			a[i][j]=b[k];
			k--;i++;		
		}
		if(i==n&&j+1<=m&&k>1){
			a[i][j]=b[k];
			k--;j++;
		}
		while(i>1&&k>1){
			a[i][j]=b[k];
			k--;i--;
		}
		if(i==1&&j+1<=m&&k>1){
			a[i][j]=b[k];
			k--;j++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==sech){
				cout <<j<<" "<<i;
			}
		}
	}
	return 0;
}
