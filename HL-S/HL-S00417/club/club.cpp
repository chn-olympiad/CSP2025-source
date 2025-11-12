#include<bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3,id;
}mem[100005];
int vis[100005];
int ans=0;
int n;
void search(int i,int sum,int l1,int l2,int l3){
	if(i==n){
		ans=max(sum,ans);
	}
	for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;	
				if(l1<n/2){
					search(i+1,sum+mem[i].a1,l1+1,l2,l3);
				}
				if(l2<n/2){
					search(i+1,sum+mem[i].a2,l1,l2+1,l3);
				}
				if(l3<n/2){
					search(i+1,sum+mem[i].a3,l1,l2,l3+1);
				}
				vis[i]=0;
			}
			
	}
}
bool cmp(node x,node y){
	if(x.a1==y.a1){
		return x.id<y.id;
	}
	return x.a1>y.a1;
}
void solve(){
	ans=0;
	cin>>n;
	memset(vis,0,sizeof(vis));
	int f2=0,f3=0;
	for(int i=1;i<=n;i++){
		cin>>mem[i].a1>>mem[i].a2>>mem[i].a3;
		f2+=mem[i].a2;
		f3+=mem[i].a3;
		mem[i].id=i;
	}
	if(f2==0&&f3==0){
		sort(mem+1,mem+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=mem[i].a1;
			cout<<ans<<"\n";
			return;
		}
	}
	search(0,0,0,0,0);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	solve();	
	}
				
	return 0;
}
