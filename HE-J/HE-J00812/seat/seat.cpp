#include<bits/stdc++.h>
using namespace std;
int n,m,a[40000],b[200][200],c,k;
bool cmp(int a,int b){
	if(a>b) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[j][i*2-1]=a[n*m-k+1];
			k--;
		}
		if(k<=0){
			break;
		}
		for(int j=n;j>=1;j--){
			b[j][i*2]=a[n*m-k+1];
			k--;
		}
		if(k==0){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==c){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
