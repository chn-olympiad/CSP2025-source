#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11];
int c[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=0;i<n*m;i++)cin>>c[i];
	int e=c[0];
	sort(c,c+n*m,cmp);
	int d=0;
	for(int i=1;i<=m;i++){//ÁÐ 
		if(i%2==1){
			for(int j=1;j<=n;j++){//ÐÐ 
				a[i][j]=c[d];
				d++;
				if(a[i][j]==e){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[i][j]=c[d];
				d++;
				if(a[i][j]==e){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}
	}
	
	
	return 0;
}
