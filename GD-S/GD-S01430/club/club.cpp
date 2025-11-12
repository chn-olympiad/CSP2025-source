#include<bits/stdc++.h>
using namespace std;
int n,a[101][101],club1[100001],zj=0,club=0,max1=0,rg[100001],p=0,l[100001],o=1;
int t,myz=0;
int f(int s,int zj){
	if(s==n+1){
		return 0;
	}
	else{
		for(int i=1;i<=3;i++){
			if(club1[i]<zj&&rg[s]==0){
				rg[s]=1;
				club1[i]++;
				p=max(p,a[s][i]+f(s+1,zj));
				l[o]=p;
				o++;
				rg[s]=0;
				club1[i]--;
				p=p-f(s+1,zj);
			}
			
		}
	}
	return p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		zj=n/2;
		for(int i=1;i<=n;i++){
			club1[i]=0;
			rg[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		f(1,zj);
		cout<<l[o-1]<<endl;
		o=0;
		p=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
