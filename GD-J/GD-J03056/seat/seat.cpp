#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[50][50]={},b[50]={},c[50][50]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int r=b[0];
	sort(b,b+n*m,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=b[i*m+j];
		}
	}
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				c[i][j]=a[i][j];
			}
		}else{
			int k=0;
			for(int j=m-1;j>=0;j--){
				c[i][j]=a[i][k];
				k++;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(c[i][j]==r){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

