//GZ-S00359 罗义凯 贵阳雅礼高级中学（贵阳市第九中学） 
#include<bits/stdc++.h>
using namespace std;
struct a{
	int myd;
	int w;
}ax[10005];
struct b{
	int myd;
	int w;
}bx[10005];
struct c{
	int myd;
	int w;
}cx[10005];
int n;
void px(){
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(ax[j].myd>ax[j-1].myd){
				ax[n]=ax[j];
				ax[j]=ax[j-1];
				ax[j-1]=ax[n];
			}
			if(bx[j].myd>bx[j-1].myd){
				bx[n]=bx[j];
				bx[j]=bx[j-1];
				bx[j-1]=bx[n];
			}
			if(cx[j].myd>cx[j-1].myd){
				cx[n]=cx[j];
				cx[j]=cx[j-1];
				cx[j-1]=cx[n];
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			ax[i].myd=a;ax[i].w=i;
			bx[i].myd=b;bx[i].w=i;
			cx[i].myd=c;cx[i].w=i;
		}
		px();
		long long su=0;
		int xa=n/2,xb=n/2,xc=n/2;
		for(int i=0;i<n;i++){
			if(ax[i].w!=-1&&xa>=1){
				if(ax[i].myd>=bx[i].myd&&ax[i].myd>=cx[i].myd){
					su+=ax[i].myd;
					int q=ax[i].w;
					xa--;
					for(int j=0;j<n;j++){
						if(ax[j].w==q){
							ax[j].myd=0;ax[j].w=-1;
						} 
						if(bx[j].w==q){
							bx[j].myd=0;bx[j].w=-1;
						} 
						if(cx[j].w==q){
							cx[j].myd=0;cx[j].w=-1;
						} 
					}
				}
			}
			if(bx[i].w!=-1&&xb>=1){
				if(bx[i].myd>=ax[i].myd&&bx[i].myd>=cx[i].myd){
					su+=bx[i].myd;
					int q=bx[i].w;
					xb--;
					for(int j=0;j<n;j++){
						if(ax[j].w==q){
							ax[j].myd=0;ax[j].w=-1;
						} 
						if(bx[j].w==q){
							bx[j].myd=0;bx[j].w=-1;
						} 
						if(cx[j].w==q){
							cx[j].myd=0;cx[j].w=-1;
						} 
					}
				}
			}
			if(cx[i].w!=-1&&xc>=1){
				if(cx[i].myd>=bx[i].myd&&cx[i].myd>=ax[i].myd){
					su+=cx[i].myd;
					int q=cx[i].w;
					xc--;
					for(int j=0;j<n;j++){
						if(ax[j].w==q){
							ax[j].myd=0;ax[j].w=-1;
						} 
						if(bx[j].w==q){
							bx[j].myd=0;bx[j].w=-1;
						} 
						if(cx[j].w==q){
							cx[j].myd=0;cx[j].w=-1;
						} 
					}
				}
			}
		}
		cout<<su<<endl;
	}
	return 0;
} 
