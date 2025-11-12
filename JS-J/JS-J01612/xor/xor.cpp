#include<bits/stdc++.h>
using namespace std;
int a[500001],xsum[500001],cnt,ans;
struct qj{
	int l,r;
}c[2000001];
bool cmp(qj a,qj b){
	if(a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		xsum[i]=(xsum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((xsum[j]^xsum[i-1])==k){
				cnt++;
				c[cnt].l=i;
				c[cnt].r=j;
			}
		}
	}
	sort(c+1,c+cnt+1,cmp);
	ans=1;
	int flag=c[1].r;
	for(int i=1;i<=cnt;i++){
		if(c[i].l>flag){
			ans++;
			flag=c[i].r;
		}
	}
	cout<<ans;
    return 0;
}
