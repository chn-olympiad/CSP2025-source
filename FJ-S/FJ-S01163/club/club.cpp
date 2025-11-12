#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[100005];
int t,ans;
bool cmp(node a,node b){
	if(a.u>b.u)return a.u<b.u;
	else if(a.v>b.v)return a.v<b.v;
	else return a.w<=b.w;
}
bool cmp1(node a,node b){
	if(a.v>b.v)return a.v<b.v;
	else if(a.u>b.u)return a.u<b.u;
	else return a.w<=b.w;
}
bool cmp2(node a,node b){
	if(a.w>b.w)return a.w<b.w;
	else if(a.u>b.u)return a.u<b.u;
	else return a.v<=b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		int q[100005]={0},l[5]={0};
		int n;
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i].u>>a[i].v>>a[i].w;
		if(n==2){
			for(int i=1;i<=n;i++){
				int s=max(a[i].u,max(a[i].v,a[i].w));
				if(s==a[i].u)q[i]=1;
				else if(s==a[i].v)q[i]=2;
				else q[i]=3;
			}
			for(int i=1;i<=n;i++){
				if(q[i]==1)l[1]++;
				else if(q[i]==2)l[2]++;
				else l[3]++;
			}
			if(l[1]<=1&&l[2]<=1&&l[3]<=1){
				for(int i=1;i<=n;i++){
					ans+=max(a[i].u,max(a[i].v,a[i].w));
				}
				cout<<ans<<"\n";
			}else {
				if(l[1]==2){
					int l1=min(a[1].u,a[2].u);
					if(l1==a[1].u&&l1!=a[2].u){
						int l2=max(a[1].v,a[1].w);
						cout<<l2+a[2].u<<"\n";
					}else if(l1!=a[1].u&&l1==a[2].u){
						int l2=max(a[2].v,a[2].w);
						cout<<l2+a[1].u<<"\n";
					}else {
						int l2=max(a[1].v,a[1].w),l3=max(a[2].v,a[2].w);
						if(l2>=l3){
							cout<<l2+a[2].u<<"\n";
						}else {
							cout<<l3+a[1].u<<"\n";
						}
					}
				}else if(l[2]==2){
					int l1=min(a[1].v,a[2].v);
					if(l1==a[1].v&&l1!=a[2].v){
						int l2=max(a[1].u,a[1].w);
						cout<<l2+a[2].v<<"\n";
					}else if(l1!=a[1].v&&l1==a[2].v){
						int l2=max(a[2].u,a[2].w);
						cout<<l2+a[1].v<<"\n";
					}else {
						int l2=max(a[1].u,a[1].w),l3=max(a[2].u,a[2].w);
						if(l2>=l3){
							cout<<l2+a[2].v<<"\n";
						}else {
							cout<<l3+a[1].v<<"\n";
						}
					}
				}else{
					int l1=min(a[1].w,a[2].w);
					if(l1==a[1].w&&l1!=a[2].w){
						int l2=max(a[1].v,a[1].u);
						cout<<l2+a[2].w<<"\n";
					}else if(l1!=a[1].w&&l1==a[2].w){
						int l2=max(a[2].v,a[2].u);
						cout<<l2+a[1].w<<"\n";
					}else {
						int l2=max(a[1].v,a[1].u),l3=max(a[2].v,a[2].u);
						if(l2>=l3){
							cout<<l2+a[2].w<<"\n";
						}else {
							cout<<l3+a[1].w<<"\n";
						}
					}
				}
			}
		}else {
			for(int i=1;i<=n;i++){
				int s=max(a[i].u,max(a[i].v,a[i].w));
				if(s==a[i].u)q[i]=1;
				else if(s==a[i].v)q[i]=2;
				else q[i]=3;
			}
			for(int i=1;i<=n;i++){
				if(q[i]==1)l[1]++;
				else if(q[i]==2)l[2]++;
				else l[3]++;
			}
			if(l[1]<=k&&l[2]<=k&&l[3]<=k){
				for(int i=1;i<=n;i++){
					ans+=max(a[i].u,max(a[i].v,a[i].w));
				}
				cout<<ans<<"\n";
			}else if(l[1]>k){
				int o=l[1]-k;
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(o){
						ans+=min(a[i].u,max(a[i].v,a[i].w));
						o--;
					}else {
						ans+=max(a[i].u,max(a[i].v,a[i].w));
					}
				}
				cout<<ans<<"\n";
			}else if(l[2]>k){
				int o=l[2]-k;
				sort(a+1,a+n+1,cmp1);
				for(int i=1;i<=n;i++){
					if(o){
						ans+=min(a[i].u,max(a[i].v,a[i].w));
						o--;
					}else {
						ans+=max(a[i].u,max(a[i].v,a[i].w));
					}
				}
				cout<<ans<<"\n";
			}else{
				int o=l[3]-k;
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n;i++){
					if(o){
						ans+=min(a[i].u,max(a[i].v,a[i].w));
						o--;
					}else {
						ans+=max(a[i].u,max(a[i].v,a[i].w));
					}
				}
				cout<<ans<<"\n";
			}
		}	
	}
}
