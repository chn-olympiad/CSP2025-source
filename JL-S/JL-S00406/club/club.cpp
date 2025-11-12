#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct Node{
	int num,cost;
}a[N];
int n;
int NUM;
bool cmp(Node a,Node b){
	if(a.num!=NUM)return 0;
	if(b.num!=NUM)return 1;
	return a.cost<b.cost;
}
void solve(){
	cin>>n;
	int x,y,z;
	int ans=0,t1=0,t2=0,t3=0;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		if(x>=y&&x>=z){
			a[i]={1,x-max(y,z)};
			t1++;
			ans+=x;
		}else if(y>=x&&y>=z){
			a[i]={2,y-max(x,z)};
			t2++;
			ans+=y;
		}else{
			a[i]={3,z-max(x,y)};
			t3++;
			ans+=z;
		}
	}
	int mx=max(max(t1,t2),t3);
	if(mx>n/2){
		if(t1>=t2&&t1>=t3){
			NUM=1;
		}else if(t2>=t1&&t2>=t3){
			NUM=2;
		}else{
			NUM=3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=mx-n/2;i++){
			ans-=a[i].cost;
		}
	}
	cout<<ans<<"\n";
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}