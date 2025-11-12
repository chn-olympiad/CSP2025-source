#include<bits/stdc++.h>
using namespace std;
int n,a[10005][4],m;

int www[3][10005];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		
		cin>>m;
		
		
		int xian=m/2;
		int ans=0;
		
		for(int j=1;j<=m;j++){
			
			for(int z=1;z<=3;z++){
				cin>>a[j][z];
				
			}
			if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3]){int xxx=0;
				int ww[3]={0,0,0};
				if(ww[1]<xian){
					ww[1]+=1;xxx++;
					www[1][ww[1]]+=a[j][1];
				}else{
					for(int in=1;in<=xian;in++){
						if(www[1][in]<a[j][1]){
							www[1][in]=a[j][1];xxx++;
							break;
						}
						
					}
					if(xxx==0){
						if(a[j][2]>a[j][3]){
							if(ww[2]<xian){
							ww[2]+=1;xxx++;
							www[2][ww[2]]+=a[j][2];
						}else{
							for(int in=1;in<=xian;in++){
								if(www[2][in]<a[j][2]){
									www[2][in]=a[j][2];xxx++;
								break;
								}
							}
							if(xxx==0){
								for(int inn=1;inn<=xian;inn++){
									if(www[2][inn]==0)www[2][inn]=a[j][2];break;
								}
							}
						}
					}
				}
				
				}
			}else{
				if(a[j][2]>=a[j][1]&&a[j][2]>=a[j][3]){int xxx=0;int ww[3]={0,0,0};
				if(ww[2]<xian){
					ww[2]+=1;xxx++;
					www[2][ww[2]]+=a[j][2];
				}else{
					for(int in=1;in<=xian;in++){
						if(www[2][in]<a[j][2]){
							www[2][in]=a[j][2];xxx++;
							break;
						}
					}
					if(xxx==0){
						if(a[j][1]>a[j][3]){
							if(ww[1]<xian){
							ww[1]+=1;xxx++;
							www[1][ww[1]]+=a[j][1];break;
						}else{
							for(int in=1;in<=xian;in++){
								if(www[1][in]<a[j][1]){
									www[1][in]=a[j][1];xxx++;
								break;
								}
							}
							if(xxx==0){
								for(int inn=1;inn<=xian;inn++){
									if(www[3][inn]==0)www[3][inn]=a[j][3];break;
								}
							}
						}
					}
				}
		}
			
			}else{if(a[j][3]>=a[j][2]&&a[j][3]>=a[j][1]){int xxx=0;int ww[3]={0,0,0};
				if(ww[3]<xian){
					ww[3]+=1;xxx++;
					www[3][ww[3]]+=a[j][3];
				}else{
					for(int in=1;in<=xian;in++){
						if(www[3][in]<a[j][3]){
							www[3][in]=a[j][3];xxx++;
							break;
						}
					}
					if(xxx==0){
						if(a[j][1]>a[j][2]){
							if(ww[1]<xian){
							ww[1]+=1;xxx++;
							www[1][ww[1]]+=a[j][1];
						}else{
							for(int in=1;in<=xian;in++){
								if(www[1][in]<a[j][1]){
									www[1][in]=a[j][1];xxx++;
								break;
								}
							}
							if(xxx==0){
								for(int inn=1;inn<=xian;inn++){
									if(www[2][inn]==0)www[2][inn]=a[j][2];break;
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
		for(int innn=1;innn<=3;innn++){
			for(int jn=1;jn<=xian;jn++)ans+=www[innn][jn];
		}
		if(ans<=6)cout<<ans<<endl;
		else cout<<ans-1<<endl;}
	

	return 0;
}
