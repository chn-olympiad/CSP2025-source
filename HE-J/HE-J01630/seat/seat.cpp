#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	int x[105];
	for(int i=1;i<=l;i++){
		cin>>x[i];
	}
	int r=x[1];
	int a[15][15];
	sort(x+1,x+l+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				int k=1;
			    a[i][j]=x[k];
			    k++;
		    }
		}else{
			for(int j=n;j>=1;j--){
				int k=n;
		    	a[i][j]=x[k];
		    	k--;
		    }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
