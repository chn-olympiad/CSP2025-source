#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1010][1010];
int czh[10000];
int ca[1010][1010];
long long CZH(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10){
	long long summ=0,x[15];
	x[1]=x1;
	x[2]=x2;
	x[3]=x3;
	x[4]=x4;
	x[5]=x5;
	x[6]=x6;
	x[7]=x7;
	x[8]=x8;
	x[9]=x9;
	x[10]=x10;
	for(int i=1;i<=k;i++){
		summ+=x[i]*czh[i];
	}
	for(int i=1;i<=k;i++){
		if(x[i]==0)continue;
		int minn=1000000;
		for(int j=1;j<=n;j++){
			minn=min(minn,ca[i][j]);
		}
		summ+=minn;
	}
	for(int i=1;i<n;i++){ 
		int minn=10000000;
		for(int j=i+1;j<=n;j++){
			if(x[i]==1||x[j]==1){
				minn=min(minn,min(ca[i][j],a[i][j]));
			}else{
				minn=min(minn,a[i][j]);
			}
		}
		summ+=minn;
	}
	return summ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,10000,sizeof(a));
	memset(ca,10000,sizeof(ca));
	for(int i=1;i<=m;i++){
		int ac,be,va;
		cin>>ac>>be>>va;
		a[ac][be]=va;
		a[be][ac]=va;
	}
	for(int i=1;i<=k;i++){
		cin>>czh[i];
		for(int j=1;j<=n;j++){
			int ll;
			cin>>ll;
			ca[i][j]=ll;
		}
	}
	long long minn=10000000;
	for(int a1=1;a1<=2;a1++){
		for(int a2=1;a2<=2;a2++){
			for(int a3=1;a3<=2;a3++){
				for(int a4=1;a4<=2;a4++){
					for(int a5=1;a5<=2;a5++){
						for(int a6=1;a6<=2;a6++){
							for(int a7=1;a7<=2;a7++){
								for(int a8=1;a8<=2;a8++){
									for(int a9=1;a9<=2;a9++){
										for(int a0=1;a0<=2;a0++){
											long long summ=0;
											if(k==0)summ=CZH(0,0,0,0,0,0,0,0,0,0);
											else if(k==1)summ=CZH(a1-1,0,0,0,0,0,0,0,0,0);
											else if(k==2)summ=CZH(a1-1,a2-1,0,0,0,0,0,0,0,0);
											else if(k==3)summ=CZH(a1-1,a2-1,a3-1,0,0,0,0,0,0,0);
											else if(k==4)summ=CZH(a1-1,a2-1,a3-1,a4-1,0,0,0,0,0,0);
											else if(k==5)summ=CZH(a1-1,a2-1,a3-1,a4-1,a5-1,0,0,0,0,0);
											else if(k==6)summ=CZH(a1-1,a2-1,a3-1,a4-1,a5-1,a6-1,0,0,0,0);
											else if(k==7)summ=CZH(a1-1,a2-1,a3-1,a4-1,a5-1,a6-1,a7-1,0,0,0);
											else if(k==8)summ=CZH(a1-1,a2-1,a3-1,a4-1,a5-1,a6-1,a7-1,a8-1,0,0);
											else if(k==9)summ=CZH(a1-1,a2-1,a3-1,a4-1,a5-1,a6-1,a7-1,a8-1,a9-1,0);
											else if(k==10)summ=CZH(a1-1,a2-1,a3-1,a4-1,a5-1,a6-1,a7-1,a8-1,a9-1,a0-1);
											minn=min(minn,summ);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<minn;
	return 0;
}
//4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4
