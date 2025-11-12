#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[11][11],r,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++)b[i][j]=a[(i-1)*n+j];
		}
		else{
			for(int j=m;j>=1;j--)b[i][j]=a[(i-1)*n+m-j+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				ans1=i,ans2=j;
			}
		}
	}
	cout<<ans1<<' '<<ans2;
	fclose(stdin);
	fclose(stdout);
} 
