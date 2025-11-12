#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN=1e6+10;
struct node{
	int l,r;
}h[MAXN];
bool cmp(node x,node y){
	return x.r<y.r;
}
int n,a[MAXN];
int cnt[MAXN],k,tot;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=(cnt[i-1]^a[i]);
	}
	if(n>5e3&&k<=1){
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==k) ans++;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==k) ans++;
			}
			int cnt1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt1++;
				}else{
					cnt1=0;
				}
				if(cnt1==2){
					ans++;
					cnt1=0;
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((cnt[i]^cnt[j-1])==k){
				h[++tot].l=j;
				h[tot].r=i;
			}
		}
	}
	sort(h+1,h+tot+1,cmp);
	int ans=0,lst=0;
	for(int i=1;i<=tot;i++){
		if(h[i].l<=lst) continue;
		ans++;
		lst=h[i].r; 
	}
	cout<<ans<<endl;
	return 0;
}
