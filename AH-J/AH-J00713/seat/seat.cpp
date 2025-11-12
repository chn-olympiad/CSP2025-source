#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=110;
PII a[N];
int n,m,num[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n*m+1,greater<PII>());
	int idx=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				num[i][j]=a[++idx].second;
			}
		}else{
			for(int i=1;i<=n;i++){
				num[i][j]=a[++idx].second;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num[i][j]==1){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}