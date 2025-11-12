#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,s[100010],id[100010];
struct node{
	int ma,mi,fa,fi;
}a[100010];
bool cmp(node x,node y){
	if(x.ma!=y.ma)return x.ma>y.ma;
	return x.mi>y.mi;
}
void solve(){
	cin>>n;
	int a1=0,a2=0,a3=0,t1=0,t2=0,t3=0;
	for(int i=1,x,y,z;i<=n;i++){
		cin>>x>>y>>z;
		if(x>=y&&y>=z){
			a[i].ma=x;
			a[i].mi=y;
			a[i].fa=1;
			a[i].fi=2;
		}else if(x>=z&&z>=y){
			a[i].ma=x;
			a[i].mi=z;
			a[i].fa=1;
			a[i].fi=3;
		}else if(y>=x&&x>=z){
			a[i].ma=y;
			a[i].mi=x;
			a[i].fa=2;
			a[i].fi=1;
		}else if(y>=z&&z>=x){
			a[i].ma=y;
			a[i].mi=z;
			a[i].fa=2;
			a[i].fi=3;
		}else if(z>=x&&x>=y){
			a[i].ma=z;
			a[i].mi=x;
			a[i].fa=3;
			a[i].fi=1;
		}else{
			a[i].ma=z;
			a[i].mi=y;
			a[i].fa=3;
			a[i].fi=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].fa==1){
			t1++;
			id[i]=1;
		}else if(a[i].fa==2){
			t2++;
			id[i]=2;
		}else t3++,id[i]=3;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=a[i].ma;
	if(t1>n/2){
		int tot=0;
		for(int i=1;i<=n;i++)
			if(id[i]==1)
				s[++tot]=a[i].ma-a[i].mi;
		sort(s+1,s+tot+1);
		for(int i=1;i<=t1-n/2;i++)
			ans-=s[i];
	}else if(t2>n/2){
		int tot=0;
		for(int i=1;i<=n;i++)
			if(id[i]==2)
				s[++tot]=a[i].ma-a[i].mi;
		sort(s+1,s+tot+1);
		for(int i=1;i<=t2-n/2;i++)
			ans-=s[i];
	}else if(t3>n/2){
		int tot=0;
		for(int i=1;i<=n;i++)
			if(id[i]==3)
				s[++tot]=a[i].ma-a[i].mi;
		sort(s+1,s+tot+1);
		for(int i=1;i<=t3-n/2;i++)
			ans-=s[i];
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	cin>>num;
	while(num--)solve();
	return 0;
}
