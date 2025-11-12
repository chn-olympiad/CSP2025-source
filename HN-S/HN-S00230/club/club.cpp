#include<bits/stdc++.h> 
using namespace std;
struct sNode{
	int x,y,z;
	int ma,maxidx,cma,cmaidx;
	int ch;
}sn[100005];
int ans,T,n,a,b,c;

bool cmp(sNode x,sNode y){
	if(x.ch==y.ch){
		if(x.ma==y.ma){
			return x.cma>y.cma;
		}
		return x.ma>y.ma;
	}
	return x.ch>y.ch;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		a=b=c=ans=0;
		for(int i=1;i<=n;i++){
			cin>>sn[i].x>>sn[i].y>>sn[i].z;
			if(sn[i].x>sn[i].y&&sn[i].x>sn[i].z){
				sn[i].maxidx=1;
				sn[i].ma=sn[i].x;
				if(sn[i].y>sn[i].z){
					sn[i].cma=sn[i].y;
					sn[i].cmaidx=2;
				}else{
					sn[i].cma=sn[i].z;
					sn[i].cmaidx=3;
				}
			}
			if(sn[i].y>sn[i].x&&sn[i].y>sn[i].z){
				sn[i].maxidx=2;
				sn[i].ma=sn[i].y;
				if(sn[i].x>sn[i].z){
					sn[i].cma=sn[i].x;
					sn[i].cmaidx=1;
				}else{
					sn[i].cma=sn[i].z;
					sn[i].cmaidx=3;
				}
			}
			if(sn[i].z>sn[i].x&&sn[i].y<sn[i].z){
				sn[i].maxidx=3;
				sn[i].ma=sn[i].z;
				if(sn[i].y>sn[i].y){
					sn[i].cma=sn[i].x;
					sn[i].cmaidx=1;
				}else{
					sn[i].cma=sn[i].y;
					sn[i].cmaidx=2;
				}
			}
			sn[i].ch=sn[i].ma-sn[i].cma;
		}
		sort(sn+1,sn+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(sn[i].maxidx==1){
				if(a==n/2){
					if(sn[i].cmaidx==2){
						if(b==n/2){
							ans+=sn[i].z;
							c++;
						}else{
							ans+=sn[i].cma; 
							b++;
						}
					}
					if(sn[i].cmaidx==3){
						if(c==n/2){
							ans+=sn[i].y;
							b++;
						}else{
							ans+=sn[i].cma; 
							c++;
						}
					}
				}else{
					a++;
					ans+=sn[i].ma; 
				}
			}
			if(sn[i].maxidx==2){
				if(b==n/2){
					if(sn[i].cmaidx==1){
						if(a==n/2){
							ans+=sn[i].z;
							c++;
						}else{
							ans+=sn[i].cma; 
							a++;
						}
					}
					if(sn[i].cmaidx==3){
						if(c==n/2){
							ans+=sn[i].x;
							a++;
						}else{
							ans+=sn[i].cma; 
							c++;
						}
					}
				}else{
					b++;
					ans+=sn[i].ma; 
				}
			}
			if(sn[i].maxidx==3){
				if(c==n/2){
					if(sn[i].cmaidx==1){
						if(a==n/2){
							ans+=sn[i].y;
							b++;
						}else{
							ans+=sn[i].cma; 
							a++;
						}
					}
					if(sn[i].cmaidx==2){
						if(b==n/2){
							ans+=sn[i].x;
							a++;
						}else{
							ans+=sn[i].cma; 
							b++;
						}
					}
				}else{
					c++;
					ans+=sn[i].ma; 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
