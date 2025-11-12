#include<bits/stdc++.h>
using namespace std;
int ans[15][15],a[105],cnt=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ans[i][j]=a[cnt];
				cnt++;
			}
		}else{
			for(int j=m;j>=1;j--){
				ans[i][j]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==x){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}