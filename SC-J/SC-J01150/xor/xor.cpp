#include<bits/stdc++.h>
using namespace std;
struct qj{
	int l,r;
}cnt[5*100005];
int n,k,a[5*100005],b[5*100005],c[5*100005],sum,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		cout<<n;
		return 0;
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[i]^b[j]==k){
				sum++;
				cnt[sum].l=i;
				cnt[sum].r=j;
			}
		}
	}
	for(int i=1;i<sum;i++){
		for(int j=i+1;j<=sum;j++){
			if((cnt[i].r-cnt[j].l)>(cnt[j].r-cnt[j].l)){
				swap(cnt[i],cnt[j]);
			}
		}
	}
	for(int i=1;i<=sum;i++){
		int temp=0;
		for(int j=cnt[i].l;j<=cnt[i].r;j++){
			if(c[j]){
				temp=1;
			}
		}
		if(temp==0){
			for(int j=cnt[i].l;j<=cnt[i].r;j++){
				c[j]=1;
			}
			ans++;
		}
	}
	cout<<ans;
	return 0;
}