#include<bits/stdc++.h>
using namespace std;
int v[15][15];
int a[105];
bool comp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,comp);
	int d=0,p=0;
	for(int i=1;i<=m;i++){
		if(d==0){
			for(int j=1;j<=n;j++){
				p++;
			    v[i][j]=a[p];
			    if(a[p]==num){
			    	cout<<i<<" "<<j;
			    	return 0;
				}
		    }
		    d=1;
		}
		else if(d==1){
			for(int j=n;j>=1;j--){
				p++;
				v[i][j]=a[p];
				if(a[p]==num){
			    	cout<<i<<" "<<j;
			    	return 0;
				}
			}
			d=0;
		}
	}
	return 0;
} 
