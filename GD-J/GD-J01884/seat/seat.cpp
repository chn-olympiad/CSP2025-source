#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500]={};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int tmp=a[0],j=1,k=0,zuo[100][100]={};
	sort(a,a+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(j==0){
			j++;
		}else if(j>m){
			j--;
		}
		while(j>0&&j<=m){
			zuo[j][i]=a[k++];
			if(i%2==1){
				j++;	
			}else{
				j--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(zuo[i][j]==tmp){
				cout<<j<<" "<<i;
				return 0;
			}	
		}
	}
} 
