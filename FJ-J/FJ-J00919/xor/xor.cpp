#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m;
const int MAXN=5e5+10;
int a[MAXN];
struct node{
	int l,r;
}s[100000010];
bool cmp(node a,node b){
	if(a.r==b.r){
		return a.l<b.l;
	}
	return a.r<b.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int kk=0;
			for(int k=j;k<=j+i-1;k++){
				kk^=a[k];
			}
			if(m==kk){
				x++;
				s[x].l=j,s[x].r=j+i-1;
			}
		}
	}
	sort(s+1,s+x+1,cmp);
	if(x==0){
		cout<<0;
		return 0;
	}
	int R=s[1].r,ans=1;
	for(int i=2;i<=x;i++){
		if(s[i].l<=R)continue;
		ans++;
		R=s[i].r;
	}
	cout<<ans;
	return 0;
}
