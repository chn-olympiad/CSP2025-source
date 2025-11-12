#include<bits/stdc++.h>
using namespace std;
long long int bpq=1;
struct bp{
	int beg;
	int end;
	long long int fy;
	long long int efy=0;
	long long int zfy=fy+efy;
}bpp[1000005];
bool dq[10045][10045],xcb[20];
int n,m,k;
bool ltt(){
	for(int i=1;i<=n;i++){
		if(dq[1][i]==false){
			return false;
		}
	}
	return true;
}
bool cmb(bp x1,bp x2){
	return x1.zfy<x2.zfy;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) dq[i][i]=true;
	for(int i=1;i<=m;i++){
		cin>>bpp[bpq].beg>>bpp[bpq].end>>bpp[bpq].fy;
		bpp[bpq].zfy=bpp[bpq].fy+bpp[bpq].efy;
		bpq++;
	}
	for(int i=1;i<=k;i++){
		int jg;
		cin>>jg;
		for(int j=1;j<=m;j++){
			cin>>bpp[bpq].fy;
			bpp[bpq].beg=i+n;
			bpp[bpq].end=j;
			bpp[bpq].efy=jg;
			bpp[bpq].zfy=bpp[bpq].fy+bpp[bpq].efy;
			bpq++;
		}
	}
	sort(bpp+1,bpp+bpq,cmb);
	long long  ans=0,bpj=1;
	while(ltt()==false){
		if(ltt()==true){
			cout<<ans;
			return 0;
		}
		int bbeg=bpp[bpj].beg,eend=bpp[bpj].end;
		if(bbeg>n){
			if(xcb[bbeg-n]==true){
				bpp[bpj].efy=0;
				bpp[bpj].zfy=bpp[bpj].fy;
			}
		}
		int zzfy=bpp[bpj].zfy;
		ans+=zzfy;
		if(bbeg>n) xcb[bbeg-n]=true;
		dq[bbeg][eend]=true;
		dq[eend][bbeg]=true;
		for(int i=1;i<=n+k;i++){
			for(int j=1;j<=n+k;j++){
				if(i==j) continue;
				if(dq[i][j]==true) continue;
				if(dq[i][bbeg]==true && dq[eend][j]==true){
					dq[i][j]=true;
					dq[j][i]=true;
				}
				if(dq[i][eend]==true && dq[bbeg][j]==true){
					dq[i][j]=true;
					dq[j][i]=true;
				}
				if(dq[i][bbeg]==true && dq[bbeg][j]==true){
					dq[i][j]=true;
					dq[j][i]=true;
				}
				if(dq[i][eend]==true && dq[eend][j]==true){
					dq[i][j]=true;
					dq[j][i]=true;
				}
			}
		}
		if(ltt()==true){
			cout<<ans;
			return 0;
		}
//		cout<<"accent.findp= Begin:"<<bbeg<<" End:"<<eend<<" Fy:"<<zzfy<<" Nfy:"<<bpp[bpj].fy<<" Efy:"<<bpp[bpj].zfy<<endl;
		bpj++;
	}
	return 0;
}

