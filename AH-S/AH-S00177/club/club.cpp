#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[1145141],aa[1145141];
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return (x.b==y.b)?x.a>y.a:x.b>y.b;
}
bool cmp3(int x,int u){
	return x>u;
}
short vis[1000005];
int dp[100005][10];
int s[1000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		cin>>n;
		bool A=1,B=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0) A=B=0;
			if(a[i].b!=0) A=0;
		}
		if(A){
			int ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].a;
			cout<<ans<<endl;
		}else if(B){
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].a;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].b-a[i].a;
			}
			cout<<ans<<endl;
		}else{
			int ans=0;
			int cnta=0,cntb=0,cntc=0,maxn;
			for(int i=1;i<=n;i++){
				aa[i].a=a[i].b+a[i].a;
				aa[i].b=a[i].c+a[i].b;
				aa[i].c=a[i].a+a[i].c;
				maxn=max(a[i].a,max(a[i].b,a[i].c));
				if(a[i].a==maxn){
					cnta++;
					vis[i]=1;
				}else if(a[i].b==maxn) cntb++,vis[i]=2;
				else cntc++,vis[i]=3;
				ans+=maxn;
			}
			if(cnta>=n/2){
				int ct=0;
				for(int i=1;i<=n;i++){
					if(vis[i]==1){
						s[++ct]=aa[i].c-max(aa[i].b,aa[i].a);
					}
				}
				sort(s+1,s+1+ct);
				for(int i=1;i<=ct-n/2;i++){
					ans+=s[i];
				}
			}
			if(cntb>=n/2){
				int ct=0;
				for(int i=1;i<=n;i++){
					if(vis[i]==2){
						s[++ct]=aa[i].a-max(aa[i].b,aa[i].c);
					}
				}
				sort(s+1,s+1+ct);
				for(int i=1;i<=ct-n/2;i++){
					ans+=s[i];
				}
			}
			if(cntc>=n/2){
				int ct=0;
				for(int i=1;i<=n;i++){
					if(vis[i]==3){
						s[++ct]=aa[i].b-max(aa[i].c,aa[i].a);
					}
				}
				sort(s+1,s+1+ct,cmp3);
				for(int i=1;i<=ct-n/2;i++){
					ans+=s[i];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
