//GZ-S00487 贵阳第十九中学 隆德耀 
#include<bits/stdc++.h>
using namespace std;

int n,a[4][100001],m;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int v=0,vd=0,vc=0,vx=0,zd[100001],cd[100001],zx[100001],su1=0,su2=0,su3=0;
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>a[1][j]>>a[2][j]>>a[3][j];
			int h1=max(a[1][j],a[2][j]),h2=max(a[1][j],a[3][j]),h3=max(a[2][j],a[3][j]);
			
			zd[j]=max(h1,h2);
			cd[j]=min(h1,a[3][j]);
			zx[j]=min(min(a[1][j],a[2][j]),h3);
			
			if(h1==h2)
			su1++;
			else
			if(h1==h3)
			su2++;
			else
			su3++;
			
			int zdt=max(su1,max(su2,su3)),cdt=min(max(su1,su2),su3),zxt=min(min(su1,su2),su3);
			
			if(zdt>m/2){
				if(cdt==m/2){
					su2--;
					su3++;
					v=vc;
				}else{
					su2--;
					su1++;
					v=vx;
				}
			}else{
				v=vd;
			}
			
			vd=v+zd[j];
			vc=v+cd[j];
			vx=v+zx[j];
		}
			int zdt=max(su1,max(su2,su3)),cdt=min(max(su1,su2),su3),zxt=min(min(su1,su2),su3);
			
			if(zdt>m/2){
				if(cdt==m/2){
					su2--;
					su3++;
					v=vc;
				}else{
					su2--;
					su1++;
					v=vx;
				}
			}else{
				v=vd;
			}
		
		cout<<v<<endl;
	}
	return 0; 
}
