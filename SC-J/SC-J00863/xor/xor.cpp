#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
struct node{
	int l,r;
}v[500010];
bool cmp(node a,node b){
	if(a.r-a.l==b.r-b.l) return a.l<b.l;
	if(a.l==b.l) return a.r<b.r;
	return a.r-a.l<b.r-b.l; 
}
int tr[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxv=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1];
		b[i]^=a[i];
		maxv=max(maxv,a[i]);
	}
	if(maxv<k) {
		cout<<0,exit(0);
	}
	if(k==0){
		int cnt=0,cnt0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
			if(a[i]==0) cnt0++;
		}
		if(cnt==n){
			cout<<n/2;
			exit(0);
		}
		if(cnt+cnt0==n){
			int ans=0,sum=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]==0) {
					ans+=(sum/2);
					sum=0;
				}
				if(a[i]==1){
					sum++;
				}
			}
			cout<<ans+cnt0;
		}
		exit(0);
	}
	else if(k==1){
		int cnt=0,cnt0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
			if(a[i]==0) cnt0++;
		}
		if(cnt+cnt0==n){
			cout<<cnt,exit(0);
		}
		exit(0);
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int temp=0;
				for(int l=i;l<=j;l++){
					temp^=a[l];
				}
				if(temp==k) {
					v[++cnt]={i,j};
				}
			}
			if(a[i]==k){
				v[++cnt]={i,i};
			}
		}
		sort(v+1,v+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++){
			bool flag=0;
			for(int j=v[i].l;j<=v[i].r;j++){
				if(tr[j]==1){
					flag=1;
					break;
				}
			}
			if(flag==0) {
				ans++;
				for(int j=v[i].l;j<=v[i].r;j++){
					tr[j]=1;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}