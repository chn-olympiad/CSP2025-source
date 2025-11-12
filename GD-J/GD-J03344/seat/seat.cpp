#include<bits/stdc++.h>
using namespace std;
int k[20][20];
int n,m,a[90],w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[cnt];
			cnt++;
		}
	}w=a[1];
	sort(a+1,a+cnt);
	bool l=1;
	cnt--;
	for(int i=1;i<=m;i++){
		if(l==1){
			for(int j=1;j<=n;j++){
				k[i][j]=a[cnt];
				cnt--;
			}l=0;
		}else{
			for(int j=n;j>=1;j--){
				k[i][j]=a[cnt];
				cnt--;
			}l=1;
		}
	}for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k[i][j]==w){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
