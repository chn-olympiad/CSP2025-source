#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500],ans[500][500],sum;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				k++;
				ans[i][j]=a[k];
				if(ans[i][j]==sum){
					cout<<j<<" "<<i;
					return 0;
					break;
					break;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				k++;
				ans[i][j]=a[k];
				if(ans[i][j]==sum){
					cout<<j<<" "<<i;
					return 0;
					break;
					break;
				}
			}
		}
	}
	return 0;
}
