#include<bits/stdc++.h>
using namespace std;
int a[50010],tot;
struct node{int l,r;}s[5000010];
bool cmp(node xx,node yy){
	if(xx.r==yy.r)return (xx.r-xx.l+1)<(yy.r-yy.l+1);
	return xx.r<yy.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	if(n>10000){
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k)cnt++;
		}
		if(k==0){
			for(int i = 2;i<=n;i++)
				if(a[i]==1&&a[i]==a[i-1]){
					a[i] = 0;
					cnt++;
				}
		}
		cout<<cnt;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i = 1;i<=n;i++)
		for(int j = i;j<=n;j++)
			if((a[i-1]^a[j])==k){
				tot++;
				s[tot].l = i,s[tot].r = j;
			}
	sort(s+1,s+1+tot,cmp);
	int pr = 0,cnt = 0;
	for(int i = 1;i<=tot;i++)
		if(pr<s[i].l)cnt++,pr = s[i].r;
	cout<<cnt;
	return 0;
}
