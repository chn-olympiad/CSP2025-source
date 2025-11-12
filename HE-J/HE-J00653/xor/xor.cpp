#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
struct node{
	int l,r;
	bool operator<(const node &b)const{
		return r<b.r;
	}
}q[N];
int a[N],sum[N];
int n,k,cnt;
int query(int l,int r){
	return sum[r]^sum[l-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(query(i,j)==k){
				cnt++;
				q[cnt].l=i;
				q[cnt].r=j;
				break;
			}
		}
	}
	sort(q+1,q+cnt+1);
	int prer=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(q[i].l>prer){
			prer=q[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
