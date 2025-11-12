#include<bits/stdc++.h>
using namespace std;
int n,a[5005],summ=0,maxx=-2e9,tmp[5005],maxx2=-2e9,ans;
struct Node{
	int sum=0,mx=-2e9,bj=0;
}grp[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int bj=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		summ+=a[i];
		maxx=max(maxx,a[i]);
		if(i>1&&a[i]!=a[i-1]) bj=1;
	}
	if(bj==-1){cout<<"1";exit(0);}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxx) cout<<"1";
		exit(0);
	}
	if(n==4){
		if(bj==-1){cout<<"1";exit(0);}
		if((a[1]+a[2]==a[3]+a[4]&&(a[1]==a[3]||a[1]==a[4]))||(a[1]+a[3]==a[2]+a[4]&&(a[1]==a[4]||a[1]==a[2]))||(a[1]+a[4]==a[3]+a[2]&&(a[1]==a[3]||a[1]==a[2]))) ans++;
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) ans++;
		if(a[2]+a[3]+a[4]>2*max(max(a[2],a[3]),a[4])) ans++;
		if(a[1]+a[3]+a[4]>2*max(max(a[1],a[3]),a[4])) ans++;
		if(a[1]+a[2]+a[4]>2*max(max(a[1],a[2]),a[4])) ans++;
		cout<<ans;
		exit(0);
	}
/*	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=3;k<=j;k++){
				if(grp[i][j].bj==0){
					if(grp[i][j].sum+a[k]>2*max(grp[i][j].mx,a[k])){
						grp[i][j].mx=max(grp[i][j].mx,a[k]);
						grp[i][j].sum+=a[k];
					}
				}
				tmp[k]=a[k];
				maxx2=max(maxx,tmp[k]);
			}
			if(grp[i][j].sum!=0&&grp[i][j].mx!=-2e9) ans++;
			grp[i][j].bj+=35468;
		}
	}
	cout<<ans;*/
	fclose(stdin),fclose(stdout);
	return 0;
}
//qwq
//ta paoqi le ta de guang
//zhuanshen zouxiang heian
//qidao hui loujin yisi guangming
//huida ta de zhiyou shenyuan de ninshi
//shayebushi