#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int p[200005],s[200005];
struct node{
	int l,r,s;
}a[5000005];
bool cmp(node a,node b){
	if(a.r==b.r){
		return a.s<b.s;
	}
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int sum=0,sumz=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i]==k){
			m++;
			a[m].l=i,a[m].r=i;
			a[i].s=1;
		}
		s[i]=s[i-1]^p[i];
		if(p[i]==1) sum++;
		if(p[i]==0) sumz++;
	}
	if((sum+sumz)==n){
		if(k==1){
			cout<<sum;
			return 0;
		}
	}
	for(int i=2;i<=n;i++){
		int x=1,y=i;
		while(y<=n){
			if((s[y]^s[x-1])==k){
				m++;
				a[m].l=x,a[m].r=y;
				a[m].s=i;
			}
			x++,y++;
		}
	}
	sort(a+1,a+m+1,cmp);
	int num=a[1].l,ans=1;
	for(int i=2;i<=m;i++){
		if(a[i].l>num){
			num=a[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
