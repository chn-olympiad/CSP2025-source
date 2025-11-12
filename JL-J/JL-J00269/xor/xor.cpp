#include<bits/stdc++.h>
using namespace std;
long long n,k,lx,ly;
long long qz[500005],a[500005],len=1,ls,cnt,js;
struct node{
	int x,y;
}q[500005];
bool cmp(node x1,node x2){
	if(x1.y==x2.y) return x1.x>x2.x;
	return x1.y<x2.y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	qz[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ls=qz[j]^qz[i-1];
			if(ls==k) q[len].x=i,q[len].y=j,len++;
		}
	}
	sort(q+1,q+len,cmp);
	for(int i=1;i<len;i++){
		if(q[i].x>js){
			js=q[i].y;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
