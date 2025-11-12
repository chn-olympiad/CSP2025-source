#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;

struct per{
	int id;//编号 
	int one;//对第1个的好感 
	int two;//对第2个的好感 
	int thr;//对第3个的好感 
}a[N];

bool vis[N];

bool cmp1(per x,per y){return x.one>y.one;}
bool cmp2(per x,per y){return x.two>y.two;}
bool cmp3(per x,per y){return x.thr>y.thr;}

int jie(){
	
	int ans=0,mx=0;
	int ch1=0,ch2=0,ch3=0;
	
	//123
	ans=0,ch1=0,ch2=0,ch3=0;
	for(int cnt=0;cnt<n;){
		sort(a+1,a+n+1,cmp1);
		if(!vis[a[1].id]&&ch1+1<=n/2){	
			ans+=a[1].one;
			a[1].one=0;a[1].two=0;a[1].thr=0;
			vis[a[1].id]=1;
			cnt++;ch1++;
		}
		sort(a+1,a+n+1,cmp2);
		if(!vis[a[1].id]&&ch2+1<=n/2){	
			ans+=a[1].two;
			a[1].one=0;a[1].two=0;a[1].thr=0;
			vis[a[1].id]=1;
			cnt++;ch2++;
		}
		sort(a+1,a+n+1,cmp3);
		if(!vis[a[1].id]&&ch3+1<=n/2){	
			ans+=a[1].thr;
			a[1].one=0;a[1].two=0;a[1].thr=0;
			vis[a[1].id]=1;
			cnt++;ch3++;
		}
	}mx=max(mx,ans);
	
	
	
	return mx;
}

void solve(){
	
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].id=i;
		cin>>a[i].one>>a[i].two>>a[i].thr;
	}
	cout<<jie()<<"\n";
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int t;cin>>t;
	while(t--)solve();
	
	return 0;
}
