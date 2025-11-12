#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n,ans,cnt[4],f;
struct stu{
	pair<int,int> x[4];
	int d;
	void st(){
		 sort(x+1,x+4);
	} 
	bool operator <(const stu p)const{
		return d>p.d;
	}
}a[100001];
void solve(){
	ans=cnt[1]=cnt[2]=cnt[3]=f=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			int x;
			cin>>x;
			a[i].x[j]={x,j};
		}
		a[i].st();
		a[i].d=a[i].x[3].f-a[i].x[2].f;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(f!=a[i].x[3].s){
			cnt[a[i].x[3].s]++;
			ans+=a[i].x[3].f;
		}
		else ans+=a[i].x[2].f;
		if(cnt[a[i].x[3].s]==n/2)f=a[i].x[3].s;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}
