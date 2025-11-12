#include<bits/stdc++.h>
using namespace std;
int t,n,a[114514][4],f[114514],nu[20086];
long long ans=0;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(nu,0,sizeof(nu));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]),nu[a[i][j]]=i;
		for(int j=1;j<=3;j++){
			while(!q.empty()) q.pop();
			for(int i=1;i<=n;i++){
				if(f[i]) continue;
				if(q.size()<n/2)
					ans+=a[i][j],q.push(a[i][j]),f[i]=1;
				else if(a[i][j]>q.top()){
					ans=ans-q.top()+a[i][j];
					f[nu[q.top()]]=0; f[i]=1;
					q.pop(); q.push(a[i][j]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
