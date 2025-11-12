#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int l,r;
} arr[500010];
int a[500010],s[500010];
bool cmp(node x,node y){
	if(x.r==y.r) return x.r-x.l<y.r-y.l;
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int sum=s[j+i-1]^s[j-1];
			if(sum==k){
				arr[++cnt]={j,j+i-1};
			}
		}
	}
	int start=0,ans=0;
	sort(arr+1,arr+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++) cout<<arr[i].l<<' '<<arr[i].r<<'\n';
	for(int i=1;i<=cnt;i++){
		if(arr[i].l>start){
			start=arr[i].r;
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
