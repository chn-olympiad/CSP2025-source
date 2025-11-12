#include<bits/stdc++.h>
using namespace std;
const int N=114514;
long long t,n,sum;
int a[N],c[4][N],b[N][4],cnt[4];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int p,long long s){
	if(p>n){
		sum=max(s,sum);
		return;
	}	
	for(int i=1;i<=3;++i){
		if(cnt[i]>=n/2)	continue;
		cnt[i]++;
		dfs(p+1,s+b[p][i]);
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int d=1;d<=t;++d){
		cin>>n;
		sum=0;
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j){
				cin>>b[i][j];
				a[i]=b[i][1];
			}
		if(n>1e4){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;++i)
				sum+=a[i];
			cout<<sum<<endl;
			continue;
		}
		dfs(1,0);
		cout<<sum<<endl;
	}
	
	return 0;
} 
