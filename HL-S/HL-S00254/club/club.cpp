#include<iostream>
#include<cstdio>
using namespace std;

int a[100005][5],n,m[5];
long long ans=-1,sum=0;
void dfs(int x,int t){
	if(x>n){
		ans=sum>ans?sum:ans;
		return;
	}
	m[t]++;
	if(m[t]>n/2){
		m[t]--;
		return;
	}
	sum+=a[x][t];
	for(int i=1;i<=3;i++){
		dfs(x+1,i);
	}
	m[t]--;
	sum-=a[x][t];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		n=0;cin>>n;ans=-1;sum=0;
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&a[j][1],&a[j][2],&a[j][3]);
		}
		dfs(1,1);
		dfs(1,2);
		dfs(1,3);
		cout<<ans<<endl;
	}
}