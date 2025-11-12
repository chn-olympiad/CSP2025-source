#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct zmws{
    int a,b,c;
}z[1000005];
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ans;
	scanf("%d",&t); 
	for(int i=1;i<=t;i++){
		int n,clm1=0,clm2=0,clm3=0;
		ans=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){ 
			scanf("%d%d%d",&z[j].a,&z[j].b,&z[j].c);
		}
		for(int j=1;j<=n;j++){
			int ma=0,mai=0;
			for(int k=1;k<=n;k++){
					if(max(z[k].a,max(z[mai].b,z[k].c))==z[k].a){
						if(clm1<=n/2)
							if(ma<z[k].a)
								ma=z[k].a,mai=k;
						
				}else{
					if(max(z[k].a,max(z[k].b,z[k].c))==z[k].b){
						if(clm2<=n/2){
							if(ma<z[k].b){
								ma=z[k].b,mai=k;
							}
						}
					}else{
						if(clm3<=n/2){
							if(ma<z[k].c){
								ma=z[k].c,mai=k;
							}	
						}
					}
				}
			}
			if(max(z[mai].a,max(z[mai].b,z[mai].c))==z[mai].a){
				ans+=z[mai].a,z[i].a=0,z[i].b=0,z[i].c=0,clm1++;
			}else{
				if(max(z[mai].a,max(z[mai].b,z[mai].c))==z[mai].b){
					ans+=z[mai].b,z[i].a=0,z[i].b=0,z[i].c=0,clm2++;
				}else{
					ans+=z[mai].c,z[i].a=0,z[i].b=0,z[i].c=0,clm3++;
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
