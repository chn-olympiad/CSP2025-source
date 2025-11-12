#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct node{
	int a[3];
}l[N];
int ans=0,cnt[3];
int bl[N];
void ini(){
	for(int i=1;i<=n;i++){
		l[i].a[0]=l[i].a[1]=l[i].a[2]=0;
		bl[i]=-1;
	}
	ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
}
int cg(int u,int v,int nans){
	if(bl[u]==v)return -1;
	if(cnt[v]*2==n)return -1;
	--cnt[bl[u]];++cnt[v];
	nans=nans-l[u].a[bl[u]]+l[u].a[v];
	bl[u]=cnt[v];
	return nans;
}
void SA(){
	double T=10000000,ap=0.999,nans=ans;
	while(T>1e-4){
		T*=ap;
		int x=rand()%n+1,y=rand()%3;
//		cout<<bl[1]<<" "<<bl[2]<<"\n";
		int org=bl[x],now=cg(x,y,nans);
		if(now==-1)continue;
		if(now>=ans){
			nans=now;
			ans=now;
//			swap(bl[x],bl[y]);
		}
		else{
			if(exp((now-ans)/T)>=1.0*rand()/RAND_MAX){
				nans=now;
			}
			else{
				nans=cg(x,org,now);
			}
		}
	}
}
void dfs(int idx,int rs){
	if(cnt[0]*2>n||cnt[1]*2>n||cnt[2]*2>n)return;
	if(idx==n+1){
		ans=max(ans,rs);
		return;
	}
	for(int i=0;i<3;i++){
		++cnt[i];
		dfs(idx+1,rs+l[idx].a[i]);
		--cnt[i];
	}
}
pair<int,int> getmax(node a){
	int mm=-1,mi=0;
	for(int o=0;o<3;o++){
		if(a.a[o]>mm){
			mm=a.a[o];
			mi=o;
		}
	}
	return {mm,mi};
}
bool cmp0(node a,node b){
	return a.a[0]>b.a[0];
}
bool cmp4(node a,node b){
	return getmax(a).first>getmax(b).first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	int t;cin>>t;
	while(t--)
	{
		cin>>n;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>l[i].a[0]>>l[i].a[1]>>l[i].a[2];
			if(l[i].a[1]!=0||l[i].a[2]!=0)f=1;
		}
		if(f==0){
			sort(l+1,l+1+n,cmp0);
			for(int i=1;i<=n;i++){
				ans+=l[i].a[0];
			}
			cout<<ans<<"\n";
			ini();
			continue;
		}
		if(n<=15){
//			if(0){
				dfs(1,0);
			cout<<ans<<"\n";
			ini();
			continue;
		}
		else{
			sort(l+1,l+1+n,cmp4);
			int stp=-1;
			for(int i=1;i<=n;i++){
				pair<int,int> p=getmax(l[i]);
				++cnt[p.second];ans+=p.first;
				bl[i]=p.second;
				if(cnt[p.second]*2==n){
					stp=i+1;
					break;
				}
			}
			if(stp!=-1)
			for(int i=stp;i<=n;i++){
				if(cnt[0]*2<n){
					bl[i]=0;
					ans+=l[i].a[0];
					++cnt[0];
				}
				else if(cnt[1]*2<n){
					bl[i]=1;
					ans+=l[i].a[1];
					++cnt[1];
				}
				else if(cnt[2]*2<n){
					ans+=l[i].a[2];
					bl[i]=2;
					++cnt[2];
				}
			}
			SA();
			cout<<ans<<"\n";
			ini();
		}
		ini();
	}
	return 0;
}