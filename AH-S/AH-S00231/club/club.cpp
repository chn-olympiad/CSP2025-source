#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
	ll x,y,z;
}a[N];
ll b[N],t1[N],t2[N],t3[N];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		ll n,ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z) t1[++cnt1]=i,ans+=a[i].x;
			else if(a[i].y>a[i].x&&a[i].y>a[i].z) t2[++cnt2]=i,ans+=a[i].y;
			else t3[++cnt3]=i,ans+=a[i].z;
		}
		if(cnt1>n/2){
			for(int i=1;i<=cnt1;i++)
				b[i]=min(a[t1[i]].x-a[t1[i]].y,a[t1[i]].x-a[t1[i]].z);
			sort(b+1,b+1+cnt1,cmp);
			for(int i=cnt1;i>n/2;i--)
				ans-=b[i];
		}
		else if(cnt2>n/2){
			for(int i=1;i<=cnt2;i++)
				b[i]=min(a[t2[i]].y-a[t2[i]].x,a[t2[i]].y-a[t2[i]].z);
			sort(b+1,b+1+cnt2,cmp);
			for(int i=cnt2;i>n/2;i--)
				ans-=b[i];
		}
		else if(cnt3>n/2){
			for(int i=1;i<=cnt3;i++)
				b[i]=min(a[t3[i]].z-a[t3[i]].x,a[t3[i]].z-a[t3[i]].y);
			sort(b+1,b+1+cnt3,cmp);
			for(int i=cnt3;i>n/2;i--)
				ans-=b[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
