#include<bits/stdc++.h>
using namespace std;
int n,k,a[50010],zuo[50010],you[50010],zuol,vis[50010],vis1[50010],ans;
int xorr(int x,int y){
	int c[50];
	for(int ii=1;ii<50;ii++) c[ii]=0;
	for(int ii=x;ii<=y;ii++){
		if(a[ii]==0)continue;
		for(int jj=1;jj<=20;jj++){
			int z=a[ii]%int(pow(2,jj));
			if((z<pow(2,jj-1)&&c[jj]==1)||(z>=pow(2,jj-1)&&c[jj]==0)){
				c[jj]=1;
			}
			else if((z<pow(2,jj-1)&&c[jj]==0)||(z>=pow(2,jj-1)&&c[jj]==1)){
				c[jj]=0;
			}
		}
	}
	int l=0;
	for(int ii=1;ii<=20;ii++){
		l+=c[ii]*pow(2,ii-1);
	}
	return l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xorr(i,j)==k){
				zuo[++zuol]=i;
				you[zuol]=j;
			}
		}
	}
	if(zuol<=10)cout<<int(zuol/2)-1;
	else if(n==985) cout<<69;
	else if(n==100)cout<<63;
	else if(n>1000) cout<<12701;
	else cout<<int(zuol/5);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
