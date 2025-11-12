//GZ-S00497 遵义市第四中学 马昭懿
#include<bits/stdc++.h>
using namespace std;

struct pp{
	int x,y,z,my,mx1,mx2;
};
pp a[100010];
long long ans;
int t;
int n;
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	cin>>t;
	a[0].mx1=1e9;
	a[0].mx2=0;
	while(t--){
		cin>>n;
		ans=0;
		int m[4]={0},m2[4]={0},m3[4]={0},m4[4]={0},m5[4]={0},z[4]={0},q=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx1=max(max(a[i].x,a[i].y),max(a[i].y,a[i].z));
			a[i].mx2=min(min(max(a[i].x,a[i].y),max(a[i].y,a[i].z)),min(max(a[i].x,a[i].y),max(a[i].x,a[i].z)));
			int z1,z2;
			if(a[i].x==a[i].mx1){
				z1=1;
			}
			if(a[i].y==a[i].mx1){
				z1=2;
			}
			if(a[i].z==a[i].mx1){
				z1=3;
			}
			if(a[i].x==a[i].mx2){
				z2=1;
			}
			if(a[i].y==a[i].mx2){
				z2=2;
			}
			if(a[i].z==a[i].mx2){
				z2=3;
			}
			for(int j=1;j<=3;j++){
				if(j==z1){
					if(z[j]<q){
						z[j]++;
						ans+=a[i].mx1;
						a[i].my=a[i].mx1;
						if(a[i].mx1-a[i].mx2<a[m[j]].mx1-a[m[j]].mx2){
							m[j]=i;
						}else if(a[i].mx1-a[i].mx2==a[m[j]].mx1-a[m[j]].mx2){
							if(a[i].mx1<a[m[j]].my){
								m[j]=i;
							}
						}else if(a[i].mx1-a[i].mx2<a[m2[j]].mx1-a[m2[j]].mx2){
							m2[j]=i;
						}else if(a[i].mx1-a[i].mx2==a[m2[j]].mx1-a[m2[j]].mx2){
							if(a[i].mx1<a[m2[j]].my){
								m2[j]=i;
							}
						}else if(a[i].mx1-a[i].mx2<a[m3[j]].mx1-a[m3[j]].mx2){
							m3[j]=i;
						}else if(a[i].mx1-a[i].mx2==a[m3[j]].mx1-a[m3[j]].mx2){
							if(a[i].mx1<a[m3[j]].my){
								m3[j]=i;
							}
						}else if(a[i].mx1-a[i].mx2<a[m4[j]].mx1-a[m4[j]].mx2){
							m4[j]=i;
						}else if(a[i].mx1-a[i].mx2==a[m4[j]].mx1-a[m4[j]].mx2){
							if(a[i].mx1<a[m4[j]].my){
								m4[j]=i;
							}
						}else if(a[i].mx1-a[i].mx2<a[m5[j]].mx1-a[m5[j]].mx2){
							m5[j]=i;
						}else if(a[i].mx1-a[i].mx2==a[m5[j]].mx1-a[m5[j]].mx2){
							if(a[i].mx1<a[m5[j]].my){
								m5[j]=i;
							}
						}
					}else{
						if(a[i].mx2>=a[m[j]].mx1+a[m[j]].mx2-2*a[m[j]].my+a[i].mx1){
							z[z2]++;
							ans+=a[i].mx2;
							a[i].my=a[i].mx2;
							if(a[i].mx1-a[i].mx2<a[m[z2]].mx1-a[m[z2]].mx2){
								m[z2]=i;
							}else if(a[i].mx1-a[i].mx2==a[m[z2]].mx1-a[m[z2]].mx2){
								if(a[i].mx1<a[m[z2]].my){
									m[z2]=i;
								}
							}else if(a[i].mx1-a[i].mx2<a[m2[z2]].mx1-a[m2[z2]].mx2){
								m2[z2]=i;
							}else if(a[i].mx1-a[i].mx2==a[m2[z2]].mx1-a[m2[z2]].mx2){
								if(a[i].mx1<a[m2[z2]].my){
									m2[z2]=i;
								}
							}else if(a[i].mx1-a[i].mx2<a[m3[z2]].mx1-a[m3[z2]].mx2){
								m3[z2]=i;
							}else if(a[i].mx1-a[i].mx2==a[m3[z2]].mx1-a[m3[z2]].mx2){
								if(a[i].mx1<a[m3[z2]].my){
									m3[z2]=i;
								}
							}else if(a[i].mx1-a[i].mx2<a[m4[z2]].mx1-a[m4[z2]].mx2){
								m4[z2]=i;
							}else if(a[i].mx1-a[i].mx2==a[m4[z2]].mx1-a[m4[z2]].mx2){
								if(a[i].mx1<a[m4[z2]].my){
									m4[z2]=i;
								}
							}else if(a[i].mx1-a[i].mx2<a[m5[z2]].mx1-a[m5[z2]].mx2){
								m5[z2]=i;
							}else if(a[i].mx1-a[i].mx2==a[m5[z2]].mx1-a[m5[z2]].mx2){
								if(a[i].mx1<a[m5[z2]].my){
									m5[z2]=i;
								}
							}
						}else{
							z[j]++;
							ans+=a[i].mx1;
							ans-=a[m[j]].mx1;
							ans+=a[m[j]].mx2;
							a[i].my=a[i].mx1;
							if(a[i].mx1-a[i].mx2<a[m2[j]].mx1-a[m2[j]].mx2){
								m[j]=i;
							}else if(a[i].mx1-a[i].mx2==a[m2[j]].mx1-a[m2[j]].mx2){
								if(a[i].mx1<a[m2[j]].my){
									m[j]=i;
								}
							}else if(a[i].mx1-a[i].mx2<a[m3[j]].mx1-a[m3[j]].mx2){
								m2[j]=i;
							}else if(a[i].mx1-a[i].mx2==a[m3[j]].mx1-a[m3[j]].mx2){
								if(a[i].mx1<a[m3[j]].my){
									m2[j]=i;
								}
							}else if(a[i].mx1-a[i].mx2<a[m4[j]].mx1-a[m4[j]].mx2){
								m3[j]=i;
							}else if(a[i].mx1-a[i].mx2==a[m4[j]].mx1-a[m4[j]].mx2){
								if(a[i].mx1<a[m4[j]].my){
									m3[j]=i;
								}
							}else if(a[i].mx1-a[i].mx2<a[m5[j]].mx1-a[m5[j]].mx2){
								m4[j]=i;
							}else if(a[i].mx1-a[i].mx2==a[m5[j]].mx1-a[m5[j]].mx2){
								if(a[i].mx1<a[m5[j]].my){
									m4[j]=i;
								}
							}else{
								m5[j]=i;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

