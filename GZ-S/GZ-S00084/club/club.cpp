//GZ-S00084 贵阳市观山湖区外国语实验中学 吴尹志遥 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N],b[N],c[N];//主 
//最小

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int za=1,xs=1,cd=1;
		int qa=1e6+6;
		int sw=1e6+6;
		int ed=1e6+6;
		int cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		
		int ans=n/2;
		int z[ans],x[ans],v[ans];
		for(int i=1;i<=n;i++){
			
			if(a[i]==max(a[i],max(b[i],c[i]))){
				if(za==n/2+1 && xs<n/2 && cd<n/2){
					int ab=a[i]+b[qa];//1
					int ac=a[i]+c[qa];//2
					int ad=b[i]+a[qa];//3
					int ae=b[i]+c[qa];//4
					int af=c[i]+a[qa];//
					int ag=c[i]+b[qa];
					if(ab=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[qa]=a[i];
						b[xs]=b[qa];	
						xs++;
					} 
					else if(ac=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[qa]=a[i];
						c[cd]=c[qa];
						cd++;
					}
					else if(ad=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[qa]=a[qa];
						b[xs]=b[i];
						xs++;
					}
					else if(ae=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						c[cd]=c[qa];
						b[xs]=b[i];
						xs++;
						cd++;
					}
					else if(af=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						c[cd]=c[i];
						a[qa]=a[qa];
						cd++;
					}
					else {
						c[cd]=c[i];
						b[xs]=b[qa];
						cd++;
						xs++;
					}
					
				}
				else {
					z[za]=a[i];
					cout<<"z[za]="<<z[za]<<endl;
					if(qa>z[za]) qa=za;
					za++;
					
				}
				
			} 
			else if(b[i]==max(a[i],max(b[i],c[i]))){
				if(xs==n/2+1 && za<n/2 && cd<n/2){
					int ab=a[i]+b[sw];//1
					int ac=a[i]+c[sw];//2
					int ad=b[i]+a[sw];//3
					int ae=b[i]+c[sw];//4
					int af=c[i]+a[sw];//
					int ag=c[i]+b[sw];
					if(ab=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[za]=a[i];
						b[sw]=b[sw];	
						za++;
					} 
					else if(ac=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[za]=a[i];
						c[cd]=c[sw];
						cd++;
						za++;
					}
					else if(ad=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[za]=a[sw];
						b[sw]=b[i];
						za++;
					}
					else if(ae=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						c[cd]=c[sw];
						b[sw]=b[i];
						cd++;
					}
					else if(af=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						c[cd]=c[i];
						a[za]=a[sw];
						cd++;
						za++;
					}
					else {
						c[cd]=c[i];
						b[sw]=b[sw];
						cd++;
					}
					
				}
				
				else {
					x[xs]=b[i];
					cout<<"x[xs]="<<x[xs]<<endl;
					if(sw>x[xs]) sw=xs;
					xs++;
					
				}
				
			}
			else if(c[i]==max(a[i],max(b[i],c[i]))){
				if(cd==n/2+1 && za<n/2 && xs<n/2){
					int ab=a[i]+b[ed];//1
					int ac=a[i]+c[ed];//2
					int ad=b[i]+a[ed];//3
					int ae=b[i]+c[ed];//4
					int af=c[i]+a[ed];//
					int ag=c[i]+b[ed];
					if(ab=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[za]=a[i];
						b[xs]=b[ed];	
						za++;
						xs++;
					} 
					else if(ac=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[za]=a[i];
						c[ed]=c[ed];
						za++;
					}
					else if(ad=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						a[za]=a[ed];
						b[xs]=b[i];
						za++;
						xs++;
					}
					else if(ae=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						c[cd]=c[ed];
						b[xs]=b[i];
						cd++;
						xs++;
					}
					else if(af=max(ab,max(ac,max(ad,max(ae,max(af,ag)))))){
						c[ed]=c[i];
						a[za]=a[ed];
						za++;
					}
					else {
						c[ed]=c[i];
						b[xs]=b[ed];
						xs++;
					}
					
				}
				
				else {
					v[cd]=c[i];
					cout<<"v[cd]="<<v[cd]<<endl;
					if(ed>v[cd]) ed=cd;
					cd++;
					
				}
				
			}
		}
		for(int i=1;i<=za-1;i++){
			cnt+=z[i];
		}
	
		for(int i=1;i<=xs-1;i++){
			cnt+=x[i];
		}
		
		for(int i=1;i<=cd-1;i++){
			cnt+=v[i];
		}
		
		cout<<cnt<<endl;	
	}
	
	
	return 0;
} 
