#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
const int INF=0x3f3f3f3f;
struct node{
	int num[4],maxn,minn,mid,x,y,z;
}a[N];
bool cmp(node a,node b){
	if(a.x!=b.x){
		return a.x>b.x;
	}
	if(a.y!=b.y){
		return a.y>b.y;
	}
	if(a.z!=b.z){
		return a.z>b.z;
	}
	return a.minn>b.minn;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans[4]={0,0,0,0},sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num[1]>>a[i].num[2]>>a[i].num[3];
			int maxn=0,minn=INF,mid=0;
			for(int j=1;j<=3;j++){
				maxn=max(maxn,a[i].num[j]);
				minn=min(minn,a[i].num[j]);
			}
			bool flag1=0,flag2=0;
			for(int j=1;j<=3;j++){
				if(flag1&&flag2){
					mid=a[i].num[j];
					break;
				}
				if(a[i].num[j]==maxn){
					flag1=1;
				}else if(a[i].num[j]==minn){
					flag2=1;
				}else{
					mid=a[i].num[j];
					break;
				}
			}
			a[i].x=maxn-mid;
			a[i].y=mid-minn;
			a[i].z=maxn-minn;
			a[i].maxn=maxn;
			a[i].minn=minn;
			a[i].mid=mid;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			int p1,p2,p3;
			bool f1=0,f2=0;
			for(int j=1;j<=3;j++){
				if(a[i].num[j]==a[i].maxn&&!f1){
					p1=j;
					f1=1;
				}else if(a[i].num[j]==a[i].mid&&!f2){
					p2=j;
					f2=1;
				}else{
					p3=j;
				}
			}
//			cout<<p1<<" "<<p2<<" "<<p3<<endl;
			if(ans[p1]<n/2){
				sum+=a[i].maxn;
				ans[p1]++;
			}else if(ans[p2]<n/2){
				sum+=a[i].mid;
				ans[p2]++;
			}else{
				sum+=a[i].minn;
				ans[p3]++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

