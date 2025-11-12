#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n;
struct node{
	int p1,p2,p3;
}a[maxn];
struct edge{
	int v,id;
}d[maxn];
bool cmp(edge x,edge y){
	return x.v<y.v;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].p1>>a[i].p2>>a[i].p3;
	int cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(max(a[i].p2,a[i].p3)<=a[i].p1)cnt1++,sum+=a[i].p1;
		else if(max(a[i].p1,a[i].p3)<=a[i].p2)cnt2++,sum+=a[i].p2;
		else cnt3++,sum+=a[i].p3;
		
	}

	for(int i=1;i<=n;i++){
		if(max(a[i].p2,a[i].p3)<=a[i].p1)d[i].v=a[i].p1-max(a[i].p2,a[i].p3);
		else if(max(a[i].p1,a[i].p3)<=a[i].p2)d[i].v=a[i].p2-max(a[i].p1,a[i].p3);
		else d[i].v=a[i].p3-max(a[i].p1,a[i].p2);
	//	cout<<i<<' '<<d[i].v<<' '<<'b'<<'\n';
		d[i].id=i;
	}
	sort(d+1,d+n+1,cmp);
	int ans=max(max(cnt1,cnt2),cnt3);
//	cout<<sum<<' '<<ans<<' '<<'a'<<'\n';
	if(ans<=n/2){
		cout<<sum<<'\n';
		return ;
	}else {
		int k=0,fl=0;
		for(int i=1;i<=n;i++){
			fl=0; int p=d[i].id;
			if(cnt1>n/2&&max(a[p].p2,a[p].p3)<=a[p].p1)fl=1;
			if(cnt2>n/2&&max(a[p].p1,a[p].p3)<=a[p].p2)fl=1;
			if(cnt3>n/2&&max(a[p].p1,a[p].p2)<=a[p].p3)fl=1;
			if(fl)k++,sum-=d[i].v;
			if(k==ans-n/2)break;
		}
		cout<<sum<<'\n';
		return ;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
} 
/*
1
10
2020 14533 18961                      
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444         
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
45min
*/
