#include<bits/stdc++.h>
using namespace std;
struct node{
	int num=0;
	int k=0;
	int x;
}s[300005];
int vis[300005];
int t;
int n;
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=300000;i++){
			vis[i]=0;
		}
		long long ans=0;
		int a=0,b=0,c=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[3*i-2].num,&s[3*i-1].num,&s[3*i].num);
			s[3*i-2].k=1;
			s[3*i-1].k=2;
			s[3*i].k=3;
			s[3*i-2].x=i;
			s[3*i-1].x=i;
			s[3*i].x=i;
		}
		sort(s+1,s+3*n+1,cmp);
		for(int i=1;i<=3*n;i++){
			if(vis[s[i].x]==0){
				if(s[i].k==1&&a<n/2){
					a++;
					ans+=s[i].num;
					vis[s[i].x]=1;
				}else if(s[i].k==2&&b<n/2){
					b++;
					ans+=s[i].num;
					vis[s[i].x]=1;
				}else if(s[i].k==3&&c<n/2){
					c++;
					ans+=s[i].num;
					vis[s[i].x]=1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
