#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	int l,r;
}c[N];
int n,k;
long long idx,a[N],b[N];
bool cmd(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int now=b[r]^b[l-1];
			if(now==k){
				c[++idx].l=l,c[idx].r=r;
			}
		}
	}
	sort(c+1,c+1+idx,cmd);
	int last_r=-1,cnt=0;
	for(int i=1;i<=idx;i++){
		if(c[i].l>last_r){
			last_r=c[i].r;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

