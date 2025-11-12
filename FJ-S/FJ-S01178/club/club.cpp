#include<bits/stdc++.h>
using namespace std;
int n,a[200006][4];
int b[200006];
int z[200006];
int rans;
int zzx;
void look_zzx(){
	if(z[1]>(n/2)){
		zzx=1;
	}
	if(z[2]>(n/2)){
		zzx=2;
	}
	if(z[3]>(n/2)){
		zzx=3;
	}
	return ;
}
int diyi,dier;
int look(int x){
	diyi=-1,dier=-1;
	for(int i=1;i<=3;i++){
		if(a[x][i]>diyi){
			dier=diyi;
			diyi=a[x][i];
		}
		else if(a[x][i]>dier){
			dier=a[x][i];
		}
	}
	return diyi-dier;
}
int hua[1111111],cnt;
void qingli(){
	cnt=0;
	rans=0;
	z[1]=0;
	z[2]=0;
	z[3]=0;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i][0]=-1;
			b[i]=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>a[i][b[i]]){
					b[i]=j;
				}
			}
			rans+=a[i][b[i]];
			z[b[i]]++;
		}
		look_zzx();
		for(int i=1;i<=n;i++){
			if(b[i]==zzx){
				cnt++;
				hua[cnt]=look(i);
			}
		}
		sort(hua+1,hua+1+cnt);
		for(int i=1;i<=cnt-(n/2);i++){
			rans-=hua[i];
		}
		cout<<rans<<"\n";
		qingli();
	}
	return 0;
}
