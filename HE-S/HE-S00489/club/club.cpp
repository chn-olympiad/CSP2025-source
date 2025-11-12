#include<bits/stdc++.h>
using namespace std;
int t,n,b[4],ans;
struct aaa{
	int x,y,z,myz,szy,xcr;
}a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		 	a[i].myz=a[i].x+a[i].y+a[i].z;
			int maxx;
			maxx=max(a[i].x,a[i].y);
			a[i].szy=max(maxx,a[i].z);
			if(a[i].szy==a[i].x){
				b[1]++;
			}else if(a[i].szy==a[i].y){
				b[2]++;
			}else{
				b[3]++;
			}
			a[i].xcr=a[i].myz-a[i].szy;
			ans+=a[i].szy;
			for(int j=1;j<=i-1;j++){
				if(a[j].xcr>a[j+1].xcr){
					swap(a[j].x,a[j+1].x);
					swap(a[j].y,a[j+1].y);
					swap(a[j].z,a[j+1].z);
					swap(a[j].myz,a[j+1].myz);
					swap(a[j].szy,a[j+1].szy);
					swap(a[j].xcr,a[j+1].xcr);
				}else if(a[j].xcr==a[j+1].xcr){
					if(a[j].szy<a[j+1].szy){
						swap(a[j].x,a[j+1].x);
						swap(a[j].y,a[j+1].y);
						swap(a[j].z,a[j+1].z);
						swap(a[j].myz,a[j+1].myz);
						swap(a[j].szy,a[j+1].szy);
						swap(a[j].xcr,a[j+1].xcr);
					}
				}
			}
		}
		if(b[1]>n/2){
			int bj=n;
			while(b[1]>n/2){
				for(int i=bj;i>=1;i--){
					if(a[i].x<a[i].y||a[i].x<a[i].z){
						continue;
					}else{
						if(a[i].y>=a[i].z){
							bj=i;
							b[1]--;
							ans=ans+a[i].y-a[i].x;
							break;
						}else{
							bj=i;
							b[1]--;
							ans=ans+a[i].z-a[i].x;
							break;
						}
					}
				}
			}		
		} 
		if(b[2]>n/2){
			int bj=n;
			while(b[2]>n/2){
				for(int i=bj;i>=1;i--){
					if(a[i].y<a[i].x||a[i].y<a[i].z){
						continue;
					}else{
						if(a[i].x>=a[i].z){
							bj=i;
							b[2]--;
							ans=ans-a[i].y+a[i].x;
							break;
						}else{
							bj=i;
							b[2]--;
							ans=ans-a[i].y+a[i].z;
							break;
						}
					}
				}
			}		
		}
		if(b[3]>n/2){
			int bj=n;
			while(b[3]>n/2){
				for(int i=bj;i>=1;i--){
					if(a[i].z<a[i].x||a[i].y>a[i].z){
						continue;
					}else{
						if(a[i].x>=a[i].y){
							bj=i;
							b[3]--;
							ans=ans-a[i].z+a[i].x;
							break;
						}else{
							bj=i;
							b[3]--;
							ans=ans-a[i].z+a[i].y;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
