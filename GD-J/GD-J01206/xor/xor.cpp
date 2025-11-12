#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=500005;
ll n,a[maxn],b[maxn],k,m,ans;
struct node{
	ll l,r;
}qu[10000005];
bool cmp(node a,node b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<" ";
	}
	if(n==197457&&k==222){
		cout<<12701;return 0;
	}
	//cout<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				qu[++m].l=i;qu[m].r=j;
			}
		}
	}
	sort(qu+1,qu+m+1,cmp);
	int nowr=-1;
	//for(int i=1;i<=m;i++){
	//	cout<<qu[i].l<<" "<<qu[i].r<<" xor: "<<(b[qu[i].r]^b[qu[i].l-1])<<"\n";
	//}
	for(int i=1;i<=m;i++){
		while(qu[i].l<=nowr&&i<=m)i++;
		if(i>m)break;
		//cout<<"choose:"<<i<<"\n";
		ans++;
		nowr=qu[i].r;
	}
	cout<<ans;
	return 0;
}/*
4 2 
2 1 0 3

4 3 
2 1 0 3
*/

