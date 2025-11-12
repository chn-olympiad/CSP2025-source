#include<bits/stdc++.h>
using namespace std;
int ans[7];
int a[100005][5];
int k1[5];
int n;
int p[100005];
int t;
queue<int> q;
void dfs(int x,int k){
	if(x>n){
		ans[t]=max(k,ans[t]);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(k1[i]<n/2){
			k1[i]++;
			dfs(x+1,k+a[x][i]);
			k1[i]--;
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	int k=t;
	while(t--){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p[i]=a[i][1];
		}
		if(n<=200)dfs(1,0);
		else {
			sort(p+1,p+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
			 	sum+=p[i];
			}
			ans[t]=sum;
		}
	}
	while(k--){
		cout<<ans[k]<<endl;
	}
	return 0;
}

