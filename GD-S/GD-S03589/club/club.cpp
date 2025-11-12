#include<bits/stdc++.h> 
using namespace std;
long long T,n,a[100005][4],mx=-1;
void dfs(long long sum,int n2,int a1,int a2,int a3){
	if(n2==n+1){
		mx=max(mx,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(a1>0&&i==1)
			dfs(sum+a[n2][i],n2+1,a1-1,a2,a3);
		if(a2>0&&i==2)
			dfs(sum+a[n2][i],n2+1,a1,a2-1,a3);
		if(a3>0&&i==3)
			dfs(sum+a[n2][i],n2+1,a1,a2,a3-1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long sum=0;
		mx=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==1){
			cout<<max(max(a[1][1],a[1][2]),a[1][3]);
			continue;
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j)continue;
					mx=max(mx,a[1][i]+a[2][j]);
				}	
			}
			cout<<mx<<endl;
			continue;
		}
		else {
			for(int i=1;i<=3;i++){
				if(i==1)
					dfs(a[1][i],2,n/2-1,n/2,n/2);
				if(i==2)
					dfs(a[1][i],2,n/2,n/2-1,n/2);
				if(i==3)
					dfs(a[1][i],2,n/2,n/2,n/2-1);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
