#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N];
struct node{
	int l,r;
}b[N];
int op=1;
int cnt;
void dfs(int d,int ans){
	cnt=max(cnt,ans);
	for(int i=d+1;i<op;i++){
		if(b[i].l>b[d].r||b[i].r<b[d].l){
			dfs(i,ans+1);
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=a[i];
		if(cnt==k){
			b[op].l=i,b[op].r=i;
			op++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			cnt=cnt^a[j];
			if(cnt==k){
				b[op].l=i,b[op].r=j;
				op++;
				break;
			}
		}
	}
	int maxn=-10000;
	for(int i=1;i<op;i++){
		cnt=-100;
		dfs(i,1);
		maxn=max(maxn,cnt);
	}
	cout<<maxn;     
	return 0;                                                                                                                                                                                                                                                                                         
}
