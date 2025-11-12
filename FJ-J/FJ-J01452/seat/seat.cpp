#include<bits/stdc++.h>
using namespace std;
int n,m;
long long g[100000];
int bj;
int xr;
int flag;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>g[i];
	}
	xr=g[1];
	sort(g+1,g+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(g[i]==xr){
			bj=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				flag++;
				if(flag==bj){
					cout<<j<<" "<<m;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				flag++;
				if(flag==bj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
