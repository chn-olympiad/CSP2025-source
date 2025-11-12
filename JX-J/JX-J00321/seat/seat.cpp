#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=0;i<=n;i++){
				ans[i][j]=a[cnt++];
				if(a[cnt-1]==x){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
		else{
			for(int k=n;k>=0;k--){
				ans[k][j]=a[cnt++];
				if(a[cnt-1]==x){
					cout<<j<<" "<<k<<endl;
					return 0;
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
		cout<<ans[i][j]<<" ";	
	}
	cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
