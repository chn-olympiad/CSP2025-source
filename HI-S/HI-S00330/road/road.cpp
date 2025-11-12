#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],maxx,huan[5][5],qmaxx,ma[5],huang[5][5],miss[5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	for(int w=1;w<=t;w++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=4;i++){
			for(int k=0;k<=4;k++){
				huan[i][k]=999999;
			}
			miss[i]=999999;
		}
		for(int i=1;i<=n;i++){
		for(int k=1;k<=3;k++){
			if(qmaxx+a[i][k]>maxx){
				if(ma[i]+1<=(n/2)){
					maxx=qmaxx+a[i][k];
					miss[k]=min(miss[k],a[i][k]);
				}
				else {
					long long mxxx=0,c=0;
					for(int w=1;w<=3;w++){
						if(w!=k){
							if(mxxx<a[i][k]-huan[k][w]){
								c=w;
								mxxx=a[i][k]-huan[k][w];
							}
						}
					}
					if(c>0){
						for(int w=1;w<=3;w++){
							if(w!=k){
								int zhu=0;
								for(int g=1;g<=3;g++){
									if(g!=w&&g!=k&&ma[zhu]<(n/2)){
										zhu=g;
									}
								}
								if(ma[w]<(n/2)){
									maxx=qmaxx+a[i][w];
									ma[w]++;//
									miss[w]=min(miss[w],a[i][w]);
									for(int q=1;q<=3;q++){
										if(q!=k){
											if(huan[k][q]>a[i][k]-a[i][q]){
												huan[k][q]=a[i][k]-a[i][q];
												huang[k][q]=i;
											}
										}
									}
								}
								else{
									if(a[i][k]-huan[k][w]-huan[w][zhu]>0&&ma[zhu]<(n/2)){
										ma[zhu]++;
										maxx=qmaxx+a[i][k]-huan[k][w]-huan[w][zhu];
										miss[zhu]=min(miss[zhu],a[huang[w][zhu]][zhu]);
										miss[w]=min(miss[w],a[huang[k][w]][w]);
										int bo=0;
										for(int q=1;q<=3;q++){
											if(q!=zhu){
												if(huan[zhu][q]>a[huang[w][zhu]][zhu]-a[huang[w][zhu]][q]){
													huan[zhu][q]=a[huang[w][zhu]][zhu]-a[huang[w][zhu]][q];
													huang[zhu][q]=huang[w][zhu];
												}
											}
											if(q!=w){
												if(huan[w][q]>a[huang[k][w]][w]-a[huang[k][w]][q]){
													huan[w][q]=a[huang[k][w]][w]-a[huang[k][w]][q];
													huang[w][q]=huang[k][w];
													bo=1;
												}
											}
										}
										if(bo==0){
											//
										}
									}
									else if(a[i][k]-huan[k][w]>a[huang[w][zhu]][w]){
										maxx=qmaxx+a[i][k]-huan[k][w]-a[huang[w][zhu]][w];
									}
									else {
										maxx=qmaxx+(a[i][k]-huan[k][w]);
									}
								}
							}
						}
					}
					for(int w=1;w<=3;w++){
						if(w!=k){
							if(huan[k][w]>a[i][k]-a[i][w]){
								huan[k][w]=a[i][k]-a[i][w];
								huang[k][w]=i;
							}
						}
					}
				}
			}
		}
	}
	cout<<maxx;
	}
	
	return 0;
}
