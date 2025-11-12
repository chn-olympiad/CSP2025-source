#include<bits/stdc++.h>
using namespace std;
long long n,cnt[4],t;
struct node{
	long long x,id,num;
}a[300005];
bool vis[100005];
bool cmp(node A,node B){
	return A.x>B.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0,s=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				int orb;
				cin>>orb;
				a[++s].x=orb;
				a[s].id=i;
				a[s].num=j;
			}
		}
		sort(a+1,a+1+s,cmp);
		for(long long i=1;i<=s;i++){
			if(!vis[a[i].id]&&cnt[a[i].num]<n/2){
				cnt[a[i].num]++;
				vis[a[i].id]=1;
				ans+=a[i].x;
			}
		}
		cout<<ans<<endl;
		memset(vis,0,sizeof(vis));
		cnt[1]=0;cnt[2]=0;cnt[3]=0;
	}
    return 0;
}
