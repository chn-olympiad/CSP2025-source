#include<bits/stdc++.h>
using namespace std;
int a[500100],ans;
bool bj[500100];
int gg(int x,int y){
	int xx[25]={0},yy[25]={0},zz=0,xy=1;
	for(int i=1;x!=0;i++){
		xx[i]=x%2;
		x=x/2;
		xy=max(xy,i);
	}
	for(int i=1;y!=0;i++){
		yy[i]=y%2;
		y=y/2;
		xy=max(xy,i);
	}
	int bt=1;
	for(int i=1;i<=xy;i++){
		if(xx[i]!=yy[i]){
			zz=zz+bt;
		}
		bt=bt*2;
	}
	return zz;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			bj[i]=1;
		}
	}
	int g;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(bj[j]==1)
			break;
			if(j==i)
				g=a[i];
			else{
				g=gg(g,a[j]);
			}
			if(g==k){
				ans++;
				for(int xx=i;xx<=j;xx++){
					bj[xx]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
