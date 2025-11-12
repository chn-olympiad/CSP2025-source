#include <bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cur=1,sum;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	cur=1;
	sum=a[1];
	sort(a+1,a+n*m+1);
	for(int j=m;j>=1;j--){
		if(j%2==0){
			for(int i=1;i<=n;i++){
				b[i][j]=a[cur];
				cur++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[cur];
				cur++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==sum){
				cout<<j<<" "<<1;
				return 0;
			}
		}
	}
	return 0;
} 
