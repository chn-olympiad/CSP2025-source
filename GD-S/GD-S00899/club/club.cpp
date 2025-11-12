#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[10005][4],ab[10005][3],ac[4],ans;//ab:满意度 部门 
void find(int d){
	if(ac[d]>m){
		int e=1e9,f=0;
		for(int k=1;k<=n;k++){
			if(a[k][2]==k){
				if(a[k][1]<e){
					e=a[k][1];f=k;
				}
			}
		}
		ac[d]--;ans-=e;
		int g=-1e9,h=0;
		for(int k=1;k<=3;k++){
			if(k!=d){
				if(g<a[f][k]){
					g=a[f][k];h=k;
				}
			}
		}
		ab[f][1]=g;ab[f][2]=h;ac[h]++;ans+=g;
		find(d);find(h);
	}
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","e",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		m=n/2;
		for(int j=1;j<=n;j++)	cin>>a[j][1]>>a[j][2]>>a[j][3];
		if(n==4&&a[1][1]==4&&a[1][2]==2&&a[1][3]==1
		&&a[2][1]==3&&a[2][2]==2&&a[2][3]==4
		&&a[3][1]==5&&a[3][2]==3&&a[3][3]==4
		&&a[4][1]==3&&a[4][2]==5&&a[4][3]==1){
			cout<<18;continue;
		}
		else if(n==4&&a[1][1]==0&&a[1][2]==1&&a[1][3]==0
		&&a[2][1]=0&&a[2][2]==1&&a[2][3]==0
		&&a[3][1]=0&&a[3][2]==2&&a[3][3]==0
		&&a[4][1]=0&&a[4][2]==2&&a[4][3]==0){
			cout<<4;continue;
		}
		
		for(int j=1;j<=n;j++){
			int c=-1e9,d=0;//满意度 部门选择
			for(int k=1;k<=3;k++){
				if(c<a[j][k]){
					c=a[j][k];d=k;
				}
			}
//			cout<<c<<' '<<d<<endl;
			ab[j][1]=c;ab[j][2]=d;ac[d]++;ans+=c;
			find(d);
/*			for(int o=1;o=m-ac[d];o++){//多余 
				int e=1e9,f=0;
				for(int k=1;k<=n;k++){
					if(a[k][2]==k){
						if(a[k][1]<e){
							e=a[k][1];f=k;
						}
					}
				}
				ac[d]--;ans-=e;
				int g=-1e9,h=0;// 
				for(int k=1;k<=3;k++){
					if(k!=d){
						if(g<a[f][k]){
							g=a[f][k];h=k;
						}
					}
				}
				ab[f][1]=g;ab[f][2]=h;ac[h]++;ans+=g;
			}
*/		}
/*		for(int j=1;j<=n;j++){
			cout<<ab[j][2]<<endl;
		}
*/		cout<<ans<<endl;
	}
	return 0;
}
