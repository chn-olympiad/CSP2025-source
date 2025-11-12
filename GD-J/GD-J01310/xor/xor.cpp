#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}s[1000005];
bool cmp(node x,node y){
	if(x.r==y.r) return x.l>y.l;
	return x.r<y.r;
}
int n,k,a[500005],cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int q=i;q<=j;q++){
				sum=sum^a[q];
			}
			if(sum==k){
				s[++cnt].l=i;
				s[cnt].r=j;
			}
		}
	}
	sort(s+1,s+1+cnt,cmp);
	int t=0;
	for(int i=1;i<=cnt;i++){
		if(s[i].l>t){
			ans++;
			t=s[i].r;
		}
	}
	cout<<ans;
	return 0;
} 
