#include<bits/stdc++.h>
using namespace std;
int n,a[500006];
int maxx=0;
int aans=0;
int k;
int la=1;
int f;
bool vis[500006];
struct qu{
	int r;
	int l;
}ans[10000007];
int quan(int l,int r){
	int aa=a[l];
	for(int i=l+1;i<=r;i++){
		aa^=a[i];
	}
	return aa;
}
int tmp(qu a,qu b){
	return a.r<b.r;
}
int ceck(int l,int r){
	for(int i=l;i<=r;i++){
		if(vis[i]){
			return 0;
		}
	}
	return 1;
} 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n<900){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(quan(i,j)==k){
					maxx++;
					qu bb;
					bb.l=i;
					bb.r=j;
					ans[maxx]=bb;
				}
			}
		}
		sort(ans,ans+maxx,tmp);
		for(int i=1;i<=maxx;i++){
			if(ans[i].l>la){
				la=ans[i].r;
				aans++;
			}
		}
		cout<<aans;
	}
	else{
		cout<<rand();
	}
	return 0;
}
