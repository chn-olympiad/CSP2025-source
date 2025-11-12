#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500010 
int _xor(int a,int b){
	int c=0,j=1;
	while(a || b){
		if(a%2 != b%2){
			c+=j;
		}
		j*=2;a/=2;b/=2;
		
	}
	return c;
}
struct dan{
	int l,r,dis;
}V[MAXN];
bool cmp(dan a,dan b){
	if(a.dis==b.dis){
		return a.l<b.l;
	}
	return a.dis<b.dis; 
}
bool insd(int l1,int r1,int l2,int r2){
	if(l1<=l2 && l2<=r1) return 1;
	if(l1<=r2 && r2<=r1) return 1;
	if(l2<=l1 && l1<=r2) return 1;
	if(l2<=r1 && r1<=r2) return 1;
	return 0;
}
int n,k,a[MAXN],b[MAXN],bldan[MAXN];
ll ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	// froepen fraopen
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		b[i]=_xor(b[i-1],a[i]);
	}
	int fh=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int val=_xor(b[r],b[l-1]);
			if(val!=k) continue;
			int dis=r-l+1;
			fh++;
			dan K={l,r,dis};
			V[fh]=K;
		}
	}
	sort(V+1,V+1+fh,cmp);
	for(int i=1;i<=fh;i++){
		int f=0;
		for(int j=1;j<i;j++){
			if(bldan[j]==0) continue;
			if(insd(V[i].l,V[i].r,V[j].l,V[j].r)) f=1;
		}
		if(f==0){
			bldan[i]=1;
			ans++;
		}
	}
	cout<<ans;
	
	
}
// IT STILL WA
// OAO
// baoli
// maybe only 40pts ;^;

// luogu guanzhu qwertytrtyuaaa thanks \ ^OwO^ /

// empty
