#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,arr[101],G[11][11],cnt,t,ind;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>arr[1];
	t=arr[1];
	for(int i=2;i<=n*m;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++) G[i][j]=++cnt;
		}else{
			for(int j=m;j>=1;j--) G[i][j]=++cnt;
		}
	}
	sort(arr+1,arr+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==t){
			ind=n*m-i+1;
			break; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(G[i][j]==ind){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
