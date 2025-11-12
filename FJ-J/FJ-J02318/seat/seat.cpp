#include<bits/stdc++.h>
using namespace std;
int p,n,m,k=1;
int ans_n,ans_m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1){
				cin>>p;
				continue;
			}
			int x;
			cin>>x;
			if(x>p){
				k++;
			}
		}
	}
	ans_m=ceil(k*1.0/n);
	int u=k%n+int(k%n==0)*n;
	if(ans_m%2==1){
		ans_n=u;
	}
	else{
		ans_n=n-u+1;
	}
	cout<<ans_m<<' '<<ans_n;
	return 0;
} 
