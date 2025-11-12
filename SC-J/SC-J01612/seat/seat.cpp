#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,r,ans[11][11],a[101];
	cin>>n>>m>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
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
			if(ans[i][j]==r) cout<<i<<" "<<j;
		}
	}
	return 0;
} 