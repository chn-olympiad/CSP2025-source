#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int a[500005];
int ans=0;
bool vis[500005];
struct p
{
	int s,t;
}id[500005];
int _max=0,sum2=0;
void dfs(int x,int z,int cnt,int d)
{
	if (x==z){
		_max=max(_max,d);
		return;
	}
	for (int i=x+1; i<=z; i++){
		if ((cnt^a[i])==k){
			d++;
			dfs(i,z,0,d);
			d--;
		}
		else {
			dfs(i,z,cnt^a[i],d);
			dfs(i,z,a[i],d);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=0,flag2=0;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		if (a[i]==k){
			sum2++;
		}
		vis[i]=0;
		if (a[i]!=1){
			flag1=1;
		}
		if (a[i]>1){
			flag2=1;
		}
	}
	if (k==0 && flag1==0){
		cout<<n/2;
		return 0;
	}
	if (k<=1 && flag2==0){
		if (k==0){
			for (int i=1; i<=n; i++){
				if (a[i]==0){
					ans++;
					continue;
				}
				if (i>1 && a[i]==1 && a[i-1]==1 && vis[i]==0 && vis[i-1]==0){
					ans++;
					vis[i]=vis[i-1]=1;
				}
			}
			cout<<ans;
			return 0;
		}
		for (int i=1; i<=n; i++){
			if (a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if (n<=100){
		int sum1=1;
		id[1].s=1;
		for (int i=1; i<=n; i++){
			if (a[i]==k){
				if (i==1){
					id[sum1].s=i+1;
					continue;
				}
				if (i==n){
					id[sum1].t=i-1;
					break;
				}
				id[sum1].t=i-1;
				id[sum1+1].s=i+1;
				sum1++;
			}
		}
		if (id[sum1].t==0){
			id[sum1].t=n;
		}
		ans=0;
		for (int i=1; i<=sum1; i++){
			_max=0;
	//		cout<<id[i].s<<" "<<id[i].t<<endl;
			dfs(id[i].s,id[i].t,a[id[i].s],0);
	//		cout<<_max<<endl;
			ans+=_max;
		}
		cout<<ans+sum2;
		return 0;
	}
//	int l=sum2,r=n;
//	while (l+1!=r){
//		int mid=(l+r)>>1;
//		if (check(mid)){
//			l=mid;
//		}
//		else {
//			r=mid;
//		}
//	}
//	cout<<l;
	dfs(1,n,a[1],0);
	cout<<_max+sum2;
	return 0;
}
