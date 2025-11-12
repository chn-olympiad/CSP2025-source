#include<bits/stdc++.h>
using namespace std;
int T;
struct node{
	int t,pos,k;
}a[300010];
bool cmp(node q,node w){
		return q.t>w.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=300005;i++){
			a[i].t=0;
			a[i].pos=0;
			a[i].k=0;
		}
		for(int i=1;i<=n*3;i+=3){
			cin>>a[i].t;
			a[i].pos=1;
			a[i].k=i;
			cin>>a[i+1].t;
			a[i+1].pos=2;
			a[i+1].k=i;
			cin>>a[i+2].t;
			a[i+2].pos=3;
			a[i+1].k=i;
		}
		sort(a+1,a+1+3*n,cmp);
		int cnt[4]={0};
		bool vis[100010]={0};
		for(int i=1;i<=3*n;i++){
			if(cnt[a[i].pos]<n/2&&vis[a[i].k]==0){
				ans+=a[i].t;
				cnt[a[i].pos]++;
				vis[a[i].k]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
