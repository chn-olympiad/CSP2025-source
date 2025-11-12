#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int a,b,c;
}x[100005];
bool vis[100005];
bool cmp1(node p,node q){
	return p.a>q.a;
}
bool cmp2(node p,node q){
	return p.b>q.b;
}
bool cmp3(node p,node q){
	return p.c>q.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,s1=0,s2=0,s3=0,ans=0;
		cin>>n;
		memset(x,0,sizeof(x));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			ans+=max(max(x[i].a,x[i].b),x[i].c);
			if(max(max(x[i].a,x[i].b),x[i].c)==x[i].a){
				s1++;
			}
			if(max(max(x[i].a,x[i].b),x[i].c)==x[i].b){
				s2++;
			}
			if(max(max(x[i].a,x[i].b),x[i].c)==x[i].c){
				s3++;
			}
		}
		if(s1*2<=n&&s2*2<=n&&s3*2<=n){
			cout<<ans<<'\n';
		}else{
			if(s1*2>=n){
				int cnt=0x3f3f3f3f,ii=1;
				sort(x+1,x+n+1,cmp1);
				for(int k=n/2;k<s1;k++){
					cnt=0x3f3f3f3f;
					for(int i=1;i<=n;i++){
						if(max(max(x[i].a,x[i].b),x[i].c)==x[i].a&&!vis[i]){
							if(cnt>x[i].a-max(x[i].b,x[i].c)){
								cnt=x[i].a-max(x[i].b,x[i].c);
								ii=i;
							}
						}
					}
					vis[ii]=1;
					ans-=cnt;
				}
			}
			if(s2*2>=n){
				int cnt=0x3f3f3f3f,ii=1;
				sort(x+1,x+n+1,cmp2);
				for(int k=n/2;k<s2;k++){
					cnt=0x3f3f3f3f;
					for(int i=1;i<=n;i++){
						if(max(max(x[i].a,x[i].b),x[i].c)==x[i].b&&!vis[i]){
							if(cnt>x[i].b-max(x[i].a,x[i].c)){
								cnt=x[i].b-max(x[i].a,x[i].c);
								ii=i;
							}
						}
					}
					vis[ii]=1;
					ans-=cnt;
				}
			}
			if(s3*2>=n){
				int cnt=0x3f3f3f3f,ii=1;
				sort(x+1,x+n+1,cmp3);
				for(int k=n/2;k<s3;k++){
					cnt=0x3f3f3f3f;
					for(int i=1;i<=n;i++){
						if(max(max(x[i].a,x[i].b),x[i].c)==x[i].c&&!vis[i]){
							if(cnt>x[i].c-max(x[i].a,x[i].b)){
								cnt=x[i].c-max(x[i].a,x[i].b);
								ii=i;
							}
						}
					}
					vis[ii]=1;
					ans-=cnt;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
