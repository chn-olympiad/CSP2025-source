#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll T,n,sum[4],to,ans;
struct STU{
	ll x,y,z,club,val;
}a[N];
bool cmp(STU a,STU b){
	return a.val<b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(sum,0,sizeof(sum));
		scanf("%lld",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			ans=ans+max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].x>=max(a[i].y,a[i].z)){
				a[i].club=1;
				a[i].val=a[i].x-max(a[i].y,a[i].z);
			}
			else if(a[i].y>=max(a[i].x,a[i].z)){
				a[i].club=2;
				a[i].val=a[i].y-max(a[i].x,a[i].z);
			} 
			else{
				a[i].club=3;
				a[i].val=a[i].z-max(a[i].x,a[i].y);
			}
			sum[a[i].club]++;
		}
		to=0;
		if(sum[1]>n/2)to=1;
		else if(sum[2]>n/2)to=2;
		else to=3;
		ll cnt=sum[to]-n/2;
		sort(a+1,a+n+1,cmp); 
		for(int i=1;i<=n;i++){
			if(cnt>0&&a[i].club==to){
				ans-=a[i].val; 
				cnt--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 
