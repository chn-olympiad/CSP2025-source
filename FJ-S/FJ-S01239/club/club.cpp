#include <bits/stdc++.h>
//#define int long long
//#define db double
using namespace std;
int T,cnt[4];

struct date{
	int a[4],c[4],d[4];
	int l1,l2;
	bool op;
}arr[100005];

bool cmp1(const date x,const date y){
	return x.l1<y.l1;
}

bool cmp2(const date x,const date y){
	int p,q;
	if(!x.op) p=x.l1;
	else p=x.l2;
	if(!y.op) q=y.l1;
	else q=y.l2;
	return p<q;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int n,ans=0,k;
		cin >> n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			int maxn=0,minn=1e9,maxi,mini,s=0;
			for(int j=1;j<=3;j++){
				cin >> arr[i].a[j];
				s+=arr[i].a[j];
				if(arr[i].a[j]>maxn) maxn=arr[i].a[j],maxi=j;
				if(arr[i].a[j]<minn) minn=arr[i].a[j],mini=j;
			}
			arr[i].c[1]=maxi,arr[i].c[3]=mini,arr[i].c[2]=6-maxi-mini;
			arr[i].d[1]=maxn,arr[i].d[3]=minn,arr[i].d[2]=s-maxn-minn;
			arr[i].l1=maxn-arr[i].d[2],arr[i].l2=arr[i].d[2]-minn;
		}
		for(int i=1;i<=n;i++){
			ans+=arr[i].d[1];
			cnt[arr[i].c[1]]++;
		}
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
			cout << ans <<"\n";
			continue;
		}
		if(cnt[1]>n/2) k=1;
		if(cnt[2]>n/2) k=2;
		if(cnt[3]>n/2) k=3;
		sort(arr+1,arr+n+1,cmp1);
		int del=0;
		for(int i=1;i<=n;i++)
			if(arr[i].c[1]==k && del<cnt[k]-n/2) ans-=arr[i].l1,del++,cnt[arr[i].c[2]]++,arr[i].op=1;
		cnt[k]-=del;
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
			cout << ans <<"\n";
			continue;
		}
		if(cnt[1]>n/2) k=1;
		if(cnt[2]>n/2) k=2;
		if(cnt[3]>n/2) k=3;
		del=0;
		sort(arr+1,arr+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(arr[i].op && arr[i].c[2]==k) ans-=arr[i].l2;
			else if(!arr[i].op && arr[i].c[1]==k) ans-=arr[i].l1;
		}
		cout << ans <<"\n";
	}
	return 0;
}
