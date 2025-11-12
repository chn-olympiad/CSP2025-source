#include<bits/stdc++.h>
using namespace std;
long long a[114514],b[114514],c[114514];
long long jiana[114514],jianb[114514],jianc[114514];
long long sumjian;
long long t,n;
long long ans,flag;
long long suma,sumb,sumc;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		suma=sumb=sumc=0;
		sumjian=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(jiana,-0x3f,sizeof(jiana));
		memset(jianb,-0x3f,sizeof(jianb));
		memset(jianc,-0x3f,sizeof(jianc));
		cin>>n;
		flag=n/2;
		long long cnta1=1,cntb1=1,cntc1=1;
		for(long long i=1;i<=n;i++){
			long long x,y,z;
			cin>>x>>y>>z; 
			if(x>=y&&x>=z){
				a[i]=x;
				b[i]=y-x;
				c[i]=z-x;
			}
			if(y>=x&&y>=z){
				b[i]=y;
				a[i]=x-y;
				c[i]=z-y;
			}
			if(z>=y&&z>=x){
				c[i]=z;
				b[i]=y-z;
				a[i]=x-z;
			}
			if(a[i]>0){
				if(suma<flag){
					suma++;
					ans+=a[i];
					jiana[cnta1]=max(b[i],c[i]);
					sort(jiana+1,jiana+cnta1+1,cmp);
					cnta1++;
//					cout<<endl<<cnta1<<endl;
				}else{
					ans+=a[i];
					long long tihuan=max(b[i],c[i]);
					if(tihuan<jiana[1]){
						sumjian+=jiana[1];
						jiana[1]=tihuan;
						sort(jiana+1,jiana+cnta1+1,cmp);
					}else{
						sumjian+=tihuan;
					}
				}
			}
			if(b[i]>0){
				if(sumb<flag){
					sumb++;
					ans+=b[i];
					jianb[cntb1]=max(a[i],c[i]);
					sort(jianb+1,jianb+cntb1+1,cmp);
					cntb1++;
				}else{
					ans+=b[i];
					long long tihuan=max(a[i],c[i]);
					if(tihuan<jianb[1]){
						sumjian+=jianb[1];
						jianb[1]=tihuan;
						sort(jianb+1,jianb+cntb1+1,cmp);
					}else{
						sumjian+=tihuan;
					}
				}
			}
			if(c[i]>0){
				if(sumc<flag){
					sumc++;
					ans+=c[i];
					jianc[cntc1]=max(b[i],a[i]);
					sort(jianc+1,jianc+cntc1+1,cmp);
					cntc1++;
				}else{
					ans+=c[i];
					long long tihuan=max(b[i],a[i]);
					if(tihuan<jianc[1]){
						sumjian+=jianc[1];
						jianc[1]=tihuan;
						sort(jianc+1,jianc+cntc1+1,cmp);
					}else{
						sumjian+=tihuan;
					}
				}
			}
//			cout<<ans<<" "<<sumjian<<endl;
//			for(int j=1;j<=n;j++){
//				cout<<jianc[j]<<" ";
//			}
//			cout<<endl;
		}
		ans+=sumjian;
		cout<<ans<<"\n";
	}
	return 0;
}
