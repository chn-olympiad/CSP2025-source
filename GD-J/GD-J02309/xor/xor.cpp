#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=1010;
struct Node{
	int l,r;
}h[N];
LL n,k,x,g[N],f[N][N];
bool cmp(Node a,Node b){
	return a.r<b.r||(a.r==b,r&&a.l<b.l);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=f[i][j-1]^g[j];
			if(f[i][j]==k){
				h[x].l=i,h[x].r=j,x++;
			}
		}
	}
	sort(h,h+x,cmp);
	cout<<x<<endl;
	return 0;
}
/*
0 2 0 2
0 1 0
0 0
0
*/
