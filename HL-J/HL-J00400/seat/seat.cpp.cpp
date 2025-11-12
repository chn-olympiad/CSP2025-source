#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long a[110][110],n,m,c[110],t,k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[k];
			if(i==1 && j==1){
				t=c[k];
			}
			k++;
		}
	}
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(t==c[i]){
			t=i;
			break;
		}
	}
	k=1;
	if(m%2==0){
		for(int len=1;len<=m;len+=2){
			for(int i=1;i<=n;i++){
				a[i][len]=k;
				k++;
			}
			for(int i=n;i>=1;i--){
				a[i][len+1]=k;
				k++;
			}
		}
	}else{
		for(int len=1;len<m;len+=2){
			for(int i=1;i<=n;i++){
				a[i][len]=k;
				k++;
			}
			for(int i=n;i>=1;i--){
				a[i][len+1]=k;
				k++;
			}
		}
		for(int i=1;i<=n;i++){
			a[i][m]=k;
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==t){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
