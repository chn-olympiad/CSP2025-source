#include <bits/stdc++.h>
using namespace std;
int n,a[5005],room[5005],num=0;
void dfs(int now,int tot,int last){
	if(now==tot){
		int sum=0,imax=0;
		for(int i=0;i<tot;i++){
			sum+=a[room[i]];
			imax=max(imax,a[room[i]]);
		}
		if(sum>2*imax){
			num++;
			num%=998244353;
		}
	}
	for(int i=last+1;i<=n;i++){
		room[now]=i;
		dfs(now+1,tot,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=n;k>=1;k--){
		dfs(0,k,0);
	}
	freopen("polygon.out","w",stdout);
	cout<<num;
	return 0;
}
