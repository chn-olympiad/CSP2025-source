#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005],n,k,cnt,ans,dis[500005];
struct qj{
	int l,r;
}q[500005];
bool cmp(qj a,qj b){
	return a.l+a.r<b.l+b.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dis[i]=dis[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((dis[j]^dis[i-1])==k){
				q[++cnt].l=i;
				q[cnt].r=j;
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int r1=0;
	for(int i=1;i<=cnt;i++){
		if(q[i].l>r1){
			ans++;
			r1=q[i].r;
		}
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
