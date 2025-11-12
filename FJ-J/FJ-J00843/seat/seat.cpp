#include<bits/stdc++.h>
using namespace std;
int n,m,t,s[110],a[11][11];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	int tmp=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=s[++t];
			}
		}else{
			for(int j=m;j>=1;j--){
				a[i][j]=s[++t];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tmp==a[i][j]){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
