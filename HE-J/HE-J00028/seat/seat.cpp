#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int q=n*m;
	int b[q+1]={};
	for(int i=1;i<=q;i++){
		cin >> b[i];
	}
	int sum=b[1],num=0;
	sort(b+1,b+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(b[i]==sum){
			num=i;
			break;
		}
	}
	int a[n+1][m+1]={};
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				a[n-j+1][i]=b[n*(i-1)+j];
			}
		}else{
			for(int j=1;j<=n;j++){
				a[j][i]=b[n*(i-1)+j];
			}			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==sum){
				cout << j << " " << i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
