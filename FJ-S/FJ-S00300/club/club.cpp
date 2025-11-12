#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int t,n,maxn[N];
struct node{
	int t1,t2,t3;
}a[N];
bool cmp(node x,node y){
	if(x.t1!=y.t1){
		if(x.t2!=y.t2) return x.t3>y.t3;
		return x.t2>y.t2;
	}
	return x.t1>y.t1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		int x=0,y=0,z=0;
		memset(maxn,0,sizeof maxn);
		for(int i=1;i<=n;i++){
			cin>>a[i].t1>>a[i].t2>>a[i].t3;
			sort(a+1,a+n+1,cmp);
			maxn[i]=max(max(a[i].t1,a[i].t2),a[i].t3);
			if(maxn[i]==a[i].t1) x++;
			if(maxn[i]==a[i].t2) y++;
			else z++;
		}
		if(max(max(x,y),z)<=n/2) {
			for(int i=1;i<=n;i++){
				sum+=maxn[i];
			}
		}else{
			for(int i=1;i<=n/2;i++){
				sum+=maxn[i];
			}
			for(int i=n/2+1;i<=n;i++){
				if(maxn[i]==a[i].t1) maxn[i]=max(a[i].t2,a[i].t3);
				if(maxn[i]==a[i].t2) maxn[i]=max(a[i].t1,a[i].t3);
				if(maxn[i]==a[i].t3) maxn[i]=max(a[i].t2,a[i].t1);
				sum+=maxn[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
