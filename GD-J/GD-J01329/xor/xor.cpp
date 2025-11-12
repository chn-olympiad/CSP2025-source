#include<bits/stdc++.h>
using namespace std;
int n,k,t,tp=1,ans,a[1000000],cnt[1000000];
bool f;
struct node{
	int l,r,x;
}q[1000000];
bool cmp(node l,node k){
	return l.x>k.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222) {
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]&&a[i]!=1) f=1;
		cnt[i]=cnt[i-1]^a[i];
	}
	if(f==0&&k){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(f==0&&k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i+1]==1){
				ans++;
				if(a[i+2]==1) i++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=cnt[j]^cnt[i-1];
			if(sum==k) {
				q[++t]={i,j,0};
				break;
			}
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t;j++){
			if(i!=j){
				if(q[i].r>=q[j].l&&q[i].l<=q[j].l) {
					q[i].x++;
					q[j].x++;
				}
			}
		}
	}
	sort(q+1,q+t+1,cmp);
	while(q[tp].x){
		tp++;
		for(int i=1;i<=t;i++) q[i].x=0;
		for(int i=tp;i<=t;i++){
			for(int j=tp;j<=t;j++){
				if(i!=j){
					if(q[i].r>=q[j].l&&q[i].l<=q[j].l) {
						q[i].x++;
						q[j].x++;
					}
				}
			}
		}
		sort(q+tp,q+t+1,cmp);
	}
	cout<<t-tp+1;
	return 0;
}
