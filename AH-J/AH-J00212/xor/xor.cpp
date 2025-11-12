#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sumx[N],cnt;
struct node{
	int l,r;
}f[N];
bool cmp(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)sumx[i]=sumx[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sumx[j]^sumx[i-1])==k){
				f[++cnt]={i,j};
				break;
			}
		}
	}
	if(cnt==0){
		printf("0");
		return 0;
	}
	sort(f+1,f+cnt+1,cmp);
	int now=1,last=0,ans=0;
	while(now<=cnt){
		while(now<=cnt&&f[now].l<=last)now++;
		if(now>cnt)break;
		int id=now,mn=f[now].r;
		for(int i=now+1;i<=cnt;i++){
			if(f[i].r<mn)mn=f[i].r,id=i;
		}
		now=id;
		last=mn,ans++;
	}
	cout<<ans;
	return 0;
}
