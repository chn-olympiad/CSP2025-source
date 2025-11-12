#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,a[10001],l=0,b[101][101],p=1,c=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	l=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-1;j++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(c/2==0){
		  for(int j=1;j<=n;j++){
			b[i][j]=a[p];
			if(a[p]==l){
				cout<<i<<" "<<j;
			}
			  if(p<=n*m){
			    p++;
		      }
		  }
		  c++;
	    }else{
	      for(int j=n;j>=1;j--){
			b[i][j]=a[p];
			if(a[p]==l){
				cout<<i<<" "<<j;
			}
			if(p<=n*m){
			  p++;
		    }
		  }
		}
	}
	return 0;
}
