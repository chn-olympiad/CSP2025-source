#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,ans;
int t,cnt[4];
struct node{
	long long st,nd,rd,maxx,demaxx;
	int macx,demacx;
};
node a[N];
bool v[N];
bool cmp(node a,node b){
	if(a.maxx==b.maxx) return a.demaxx<b.demaxx;
	else return a.maxx>b.maxx;
}
void dfs(int tot,long long sum,int fi,int se,int th){
	if(tot==n+1){
		ans=max(ans,sum);
		return ;
	}
		if(fi<(n/2)) dfs(tot+1,sum+a[tot].st,fi+1,se,th);
		if(se<(n/2)) dfs(tot+1,sum+a[tot].nd,fi,se+1,th);
		if(th<(n/2)) dfs(tot+1,sum+a[tot].rd,fi,se,th+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		
		ans=0;
		cin>>n;
		int need=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].st>>a[i].nd>>a[i].rd;
			a[i].maxx=max(a[i].st,max(a[i].nd,a[i].rd));
			if(a[i].maxx==a[i].st){
				a[i].demaxx=max(a[i].nd,a[i].rd);
				a[i].macx=1;
			}
			else if(a[i].maxx==a[i].nd){
				a[i].demaxx=max(a[i].st,a[i].rd);
				a[i].macx=2;
			}
			else{
				a[i].demaxx=max(a[i].nd,a[i].st);
				a[i].macx=3;
			}
			if(a[i].demacx==a[i].st&&a[i].macx!=1) a[i].demacx=1;
			else if(a[i].demacx==a[i].nd&&a[i].macx!=2) a[i].demacx=2;
			else a[i].demacx=3;
		}
		if(n<=20){
			for(int i=1;i<=n;i++){
				v[i]=0;
			}
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
//			cout<<a[i].macx<<" "<<a[i].demacx<<endl;
			if(cnt[a[i].macx]<need){
				ans+=a[i].maxx;
				cnt[a[i].macx]++;
			}
			else{
				ans+=a[i].demaxx;
				cnt[a[i].demacx]++;
			}
//			cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
