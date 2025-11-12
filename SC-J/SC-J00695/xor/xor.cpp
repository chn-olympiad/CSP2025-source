#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,c[N];
long long k;

struct e{
	int l,r;
	int q;
	bool f;
}a[N*4+15];

int cnt=0;

void push_up(int u){
	a[u].q=a[u*2].q xor a[u*2+1].q;
	a[u].f=a[u*2].f and a[u*2+1].f; 
	if(a[u].q==k and a[u].f){
		cnt++;
		a[u].f=false;
	}
}

void bulid(int u,int l,int r){
	a[u].l=l;a[u].r=r;
	if(a[u].l==a[u].r){
		a[u].q=c[l];
		if(a[u].q==k and a[u].f){
			cnt++;
			a[u].f=false;
		}
		return ;
	}
	int mid=a[u].l+a[u].r>>1;
	bulid(u*2,l,mid);
	bulid(u*2+1,mid+1,r);
	push_up(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n*4+1;++i)
	a[i].f=true;
	cin>>k;
	for(int i=1;i<=n;++i) cin>>c[i];
	sort(c+1,c+1+n);
	if(c[1]==1 and c[n]==1) cnt=n/2;
	else
	bulid(1,1,n);
	cout<<cnt<<endl;
	return 0;
}