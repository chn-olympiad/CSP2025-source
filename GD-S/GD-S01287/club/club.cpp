#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n,maxx[100010],jsq[100010];
int ans=0,cnt;
int jf[100010][4][4];
int po[4];
struct damn{
	int t[5];
}a[100010];
bool cmp(damn x,damn y){
	return x.t[1]>y.t[1];
}
int jdz(int x){
	if(x<0) return -x;
	return x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		cnt=n/2;
		for(int i=1;i<=n;i++) 
		for(int j=1;j<=3;j++) {  //输入与预处理 
			cin>>a[i].t[j];
			if(j==1) {maxx[i]=a[i].t[j],jsq[i]=1;continue;}
			else if(a[i].t[j]>maxx[i])
			maxx[i]=a[i].t[j],jsq[i]=j;
			jf[i][1][2]=jf[i][2][1]=jdz(a[i].t[1]-a[i].t[2]);
			jf[i][1][3]=jf[i][3][1]=jdz(a[i].t[1]-a[i].t[3]);
			jf[i][3][2]=jf[i][2][3]=jdz(a[i].t[3]-a[i].t[2]);
		}
		for(int i=1;i<=n;i++){
			po[jsq[i]]++;	
		}
		if(po[1]<=cnt&&po[2]<=cnt&&po[3]<=cnt){
			for(int i=1;i<=n;i++)
			ans+=maxx[i];
//			cout<<maxx[i]<<' ';
//			cout<<"\n";
			cout<<ans<<"\n";
			continue;
		}else{
			bool bom=0,bap=0;
			for(int i=1;i<=n;i++){
				if(a[i].t[2]!=0||a[i].t[3]!=0){bom=1;break;}
				if(a[i].t[3]!=0){bap=1;continue;}
			}
			if(!bom){
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=cnt;i++) ans+=a[i].t[1];
				cout<<ans<<"\n";
				continue;
			}
			if(!bap){
				int zzt=0;
				int zy[100010];
				for(int i=1;i<=n;i++){
					if(a[i].t[1]>=a[i].t[2]){
						zzt++;
						ans+=a[i].t[1];
					}else{
						ans+=a[i].t[2];
					}
//					cout<<ans<<' ';
				}
					if(zzt>cnt){
						zzt-=cnt;
						int we=1;
						for(int i=1;i<=n;i++){
							if(a[i].t[1]>=a[i].t[2]){
								zy[we]=a[i].t[1]-a[i].t[2];
								we++;
							}
						}
						sort(zy+1,zy+1+we);
//						cout<<"zy:";
//						for(int i=1;i<=we;i++)
//						cout<<zy[i]<<" ";
//						cout<<"\n";
						for(int i=2;i<=zzt+1;i++)
						ans-=zy[i];
						cout<<ans<<" 1\n";
						continue;
					}else if(zzt<cnt){
						zzt=cnt-zzt+1;
						int we=1;
						for(int i=1;i<=n;i++){
							if(a[i].t[2]>=a[i].t[1]){
								zy[we]=a[i].t[2]-a[i].t[1];
								we++;
							}
						}
						sort(zy+1,zy+1+we);
//						cout<<"zzt="<<zzt<<"zy:";
//						for(int i=1;i<=we;i++)
//						cout<<zy[i]<<" ";
//						cout<<"\n";
						for(int i=1;i<=zzt;i++)
						ans-=zy[i];
						cout<<ans<<" 2\n";
						continue;
					}
				
			}
			
		}
	}
	return 0;
} 

