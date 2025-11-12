#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
struct node{
	int l,r;
}qujian[500010];
int cnt;
int ans;

bool cmp(node x,node y){
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
void f(int depth,int nn,int m){
	if(depth>cnt){
		if(nn>ans) ans=nn;
		return;
	}
	if(qujian[depth].l>qujian[m].r){
		f(depth+1,nn+1,depth);
	}
	f(depth+1,nn,m);
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j<=n;j++){
			s=s^a[j];
			if(s==k){
				cnt++;
				qujian[cnt].l=i;
				qujian[cnt].r=j;
				break;
			}
		}
	} 
	sort(qujian+1,qujian+1+cnt,cmp);
	f(1,0,0);
	cout<<ans;
	return 0;
} 