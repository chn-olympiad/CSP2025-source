#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++k];
		}
	}
	int a1=a[1];
	sort(a,a+k+1);
	for(int i=k;i>0;i--){
		if(a[i]==a1){
			int c=(k-i)/n;
			if(c*m!=k)c++;
			int r;
			if(c%2==0){
				r=k-i+1-(c-1)*n;
				r=m-r+1;	
			}
			else r=k-i+1-(c-1)*n;
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
