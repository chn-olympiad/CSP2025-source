#include<bits/stdc++.h>
using namespace std;
int cnt[5],a[3][500005],b[10],path[500005],n,_max=-1;
int dfs(int t,int sum){
	if(t>n){
		return sum;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
	//		cout<<_max<<" "<<t<<" "<<sum<<endl;
			path[t]=i;
			_max=max(_max,dfs(t+1,sum+a[i][t]));
			cnt[i]--;
		}	
	}
	return _max;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			//cin>>a[1][i]>>a[2][i]>>a[3][i];
			scanf("%d %d %d",&a[1][i],&a[2][i],&a[3][i]);
		}
		cout<<dfs(1,0)<<endl;
		_max=-1;
	}
	return 0;
}
