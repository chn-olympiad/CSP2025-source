#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,lim;
int peo[N][5];
int sum=0,ans=0;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int a,int b,int c,int num){
	if(a>lim || b>lim || c>lim) return ;
	if(num==n+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1 && a<lim){
			sum+=peo[i][num];
			dfs(a+1,b,c,num+1);
			sum-=peo[i][num];
		}
		if(i==2 && b<lim){
			sum+=peo[i][num];
			dfs(a,b+1,c,num+1);
			sum-=peo[i][num];
		}
		if(i==3 && c<lim){
			sum+=peo[i][num];
			dfs(a,b,c+1,num+1);
			sum-=peo[i][num];
		}
	}
	return ;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		lim=n/2;
		sum=0;
		ans=0;
		int s2=0,s3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>peo[j][i];
				if(j==2 && peo[j][i]==0) s2++;
				if(j==3 && peo[j][i]==0) s3++;
			}
		}
		if(s2==n && s3==n){
			sort(peo[1]+1,peo[1]+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=peo[1][i];
			}
			cout<<sum<<endl;
			continue;
		}
		dfs(0,0,0,1);
		cout<<ans<<endl;
	}
	return 0;
}
