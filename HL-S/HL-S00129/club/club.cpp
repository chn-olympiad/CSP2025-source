#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100001],d,h,k,m=-1,l,y,u;
long long e[100001],f[100001],g[100001],yi[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){//循环Ada组
		cin>>b;
		d=b/2;//zuiduoxiang
		for(int o=1;o<=b;o++){//循环Bxiao组
			cin>>e[o]>>f[o]>>g[o];
		}
		//cout<<d;
		for(int q=1;q<=d;q++){
			h=b-q;
			h=min(d,h);
			//cout<<h;
			for(int o=1;o<=b;o++){
				m+=e[o];
				for(int n=1;n<=h;n++){//2
					k=h-n;//3
					for(int p=1;p<=b;p++){
						t+=f[p];
						if(k>0){
							for(int l=1;l<=k;l++){
								for(int r=1;r<=b;r++){
									u+=g[r];
									y=0;
									if(p!=o&&r!=p&&r!=o){
										y=m+y+u;
										m=max(m,y);
									
									}
								}
							}
						}
						else if(k==0&&p!=o){
							l=e[o]+f[p];
							m=max(m,l);
							//cout<<m;
						}
					}
				}
			}
		}
		yi[i]=m;
	}
	for(int i=1;i<=a;i++){	 		
		cout<<yi[i]<<endl;
	}
	return 0;
}