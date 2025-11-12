#include<bits/stdc++.h>
using namespace std;
int a[505],b,c[25][25];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1){
		int y;cin>>y;
		cout<<y;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[j+n*(i-1)];
			 if(j==1&&i==1){
			 	b=a[j];	
			 }
			 //cout<<a[j];
		}
	}
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<a[j]<<endl;
			if(a[j+n*(i-1)]==b){
				//cout<<1;
				if(i%2==1){
					cout<<i<<' '<<j;
				}
				else{
					cout<<i<<' '<<j+n-1;
				}
				//cout<<c;
				return 0;
			}
		}
	}
	return 0;
} 