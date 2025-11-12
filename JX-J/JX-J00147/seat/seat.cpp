#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105],s[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				s[i][j]=a[k];
			}
		}
		else{
			for(int j=m;j>=1;j--){
				k++;
				s[i][j]=a[k];
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==x){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
