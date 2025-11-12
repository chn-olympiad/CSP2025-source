#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls k<<1
#define rs k<<1|1
#define maxn 200005
int n,f[5][maxn],ca,cb,cc,dy[maxn];
struct node{
	int x,y,z;
}a[maxn]; 
vector<int> b[5]; 
void solve(){
	cin>>n;
	int ans=0;
	b[1].clear(),b[2].clear(),b[3].clear();
	ca=cb=cc=0;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[i]={x,y,z};
		if(x>=y&&x>=z){
			ca++;
			b[1].push_back(i);
			ans+=x;
		}
		else if(y>=x&&y>=z){
			cb++;
			b[2].push_back(i);
			ans+=y;
		}
		else {
			cc++;
			b[3].push_back(i);
			ans+=z;
		}
	}
	int cnt=0;
	if(ca>n/2){
		for(int i:b[1]){
			dy[++cnt]=min(a[i].x-a[i].y,a[i].x-a[i].z); 
		}
		sort(dy+1,dy+cnt+1);
		int i=1;
		while(cnt>n/2){
			ans-=dy[i];
			cnt--;
			i++;
		}
	}
	if(cb>n/2){
		for(int i:b[2]){
			dy[++cnt]=min(a[i].y-a[i].x,a[i].y-a[i].z); 
		}
		sort(dy+1,dy+cnt+1);
		int i=1;
		while(cnt>n/2){
			ans-=dy[i];
			cnt--;
			i++;
		}
	}
	if(cc>n/2){
		for(int i:b[3]){
			dy[++cnt]=min(a[i].z-a[i].x,a[i].z-a[i].y); 
		}
		sort(dy+1,dy+cnt+1);
		int i=1;
		while(cnt>n/2){
			ans-=dy[i];
			cnt--;
			i++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	
	return 0;
}
