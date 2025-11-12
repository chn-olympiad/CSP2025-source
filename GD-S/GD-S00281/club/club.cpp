#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,sum[5],temp,pre;
struct node{
	int x,y,z,dis,to;
}a[100005];
bool cmp(node a,node b){return a.dis<b.dis;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum[1]=sum[2]=sum[3]=0;
		pre=1,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) a[i].to=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) a[i].to=2;
			else a[i].to=3;
			sum[a[i].to]++;
			if(a[i].x<a[i].y) swap(a[i].x,a[i].y);
			if(a[i].y<a[i].z) swap(a[i].y,a[i].z);
			if(a[i].x<a[i].y) swap(a[i].x,a[i].y);
			a[i].dis=a[i].x-a[i].y;
			ans+=a[i].x;
		}
		sort(a+1,a+1+n,cmp);
		if(sum[1]>n/2) temp=1;
		if(sum[2]>n/2) temp=2;
		if(sum[3]>n/2) temp=3;
		if(sum[temp]>n/2){
			while(sum[temp]>n/2){
				if(a[pre].to==temp){
					sum[temp]--;
					ans-=a[pre].dis;
				}
				pre++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
