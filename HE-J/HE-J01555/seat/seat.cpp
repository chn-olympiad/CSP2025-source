#include <bits/stdc++.h>
using namespace std;
int a[110],b[11][11];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in",'w',stdin);
	freopen("seat.out",'r',stdout);
	int n,m,r,q=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+(n*m)+1,cmp);	
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[q];
				q++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[q];
				q++;
			}
		}
	}                  
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[j][i]==r){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
