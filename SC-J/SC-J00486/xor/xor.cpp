#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt,n,k,a[500005],qzh[500005],ans,sub1,sub1_2,del[5000005];
struct node{
	int l,r;
}qj[5000005];
bool cmp(node a,node b){
	if(a.l!=b.l) return a.l<b.l;
	return a.r>b.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]^a[i];
		sub1=max(sub1,a[i]);
		sub1_2+=a[i];
	}
	if(sub1<=1){
		if(sub1_2==n){
			if(k==1)cout<<n<<endl;
			else cout<<0<<endl;
		}
		else {
			if(k==1)cout<<sub1_2<<endl;
			else cout<<n-sub1_2<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ans1=qzh[j]^qzh[i-1];
			if(ans1==k){
				qj[++cnt].l=i;qj[cnt].r=j;
			}
		}
	}
	sort(qj+1,qj+1+cnt,cmp);
	int mr=0;
	for(int i=1;i<=cnt;i++){
		if(qj[i].r<qj[i-1].r){
			int j=i-1;
			while(qj[j].r>qj[i].r){
				del[j]=1;
				j--;
			}
		}
	}
	mr=0;
	for(int i=1;i<=cnt;i++){
		if(del[i]){
			del[i]=0;
			continue;
		}
		if(qj[i].l>mr){
			ans++;
			mr=qj[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;
}