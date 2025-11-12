#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt,ans=1,s;
struct node{
	int l,r;
}b[10000005];
bool cmp(node u,node v){
	if(u.r!=v.r){
		return u.r<v.r;
	}
	return u.l<v.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				b[++cnt].l=j;
				b[cnt].r=i;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	s=b[1].r;
	for(int i=2;i<=cnt;i++){
		if(b[i].l>s){
			ans++;
			s=b[i].r;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
