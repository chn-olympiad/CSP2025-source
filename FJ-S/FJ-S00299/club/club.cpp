#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#define auto long long
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n,ans=0;
		long long a[200005],b[200005],c[200005];
		bool axt[200005],bxt[200005],cxt[200005];
		cin>>n;
		for(long long i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		long long a1[200005],b1[200005],c1[200005];
		long long anum=0,bnum=0,cnum=0;
		for(long long i=1;i<=n;i++){
			if(a[i]>b[i]&&a[i]>c[i]) a1[i]=a[i],anum++;
			else if(b[i]>a[i]&&b[i]>c[i]) b1[i]=b[i],bnum++;
			else if(c[i]>b[i]&&a[i]<c[i]) c1[i]=c[i],cnum++;
			else if(a[i]==b[i]&&a[i]==c[i]) axt[i]=1,bxt[i]=1,cxt[i]=1;
			else if(a[i]==b[i]) axt[i]=1,bxt[i]=1;
			else if(b[i]==c[i]) bxt[i]=1,cxt[i]=1;
			else if(a[i]==c[i]) axt[i]=1,cxt[i]=1;
		}for(long long i=1;i<=n;i++){
			if(axt[i]==1&&bxt[i]==1&&cxt[i]==1)continue;
			else if(axt[i]==1&&bxt[i]==1){
				if(anum<bnum)a1[i]=a[i],anum++;
				else b1[i]=b[i],bnum++;
			}else if(axt[i]==1&&cxt[i]==1){
				if(anum<cnum)a1[i]=a[i],anum++;
				else c1[i]=c[i],cnum++;
			}else if(bxt[i]==1&&cxt[i]==1){
				if(bnum<cnum)b1[i]=b[i],bnum++;
				else c1[i]=c[i],cnum++;
			}
		}if(anum>(n/2)||bnum>(n/2)||cnum>(n/2)){
			for(int i=1;i<=n;i++){
				cout<<a1[i]<<" "<<b1[i]<<" "<<c1[i]<<endl;
			}cout<<endl;
			long long adc[200005]={},bdc[200005]={},cdc[200005]={};
			for(long long i=1;i<=n;i++){
				if(axt[i]==1&&bxt[i]==1&&cxt[i]==1)continue;
				if(a[i]) adc[i]=0,bdc[i]=a[i]-b[i],cdc[i]=c[i]-a[i];
				if(b[i]) adc[i]=b[i]-a[i],bdc[i]=0,cdc[i]=b[i]-c[i];
				if(c[i]) adc[i]=c[i]-a[i],bdc[i]=c[i]-b[i],cdc[i]=0;
			}if(anum>n/2){
				while(anum>n/2){
					long long minb=0xf777,minc=0xf777,bi=0,ci=0;
					for(long long i=1;i<=n;i++){
						if(axt[i]==1&&bxt[i]==1&&cxt[i]==1)continue;
						if(a1[i]){
							if(minb>bdc[i]){
								minb=bdc[i];
								bi=i;
							}if(minc>cdc[i]){
								minc=cdc[i];
								ci=i;
							}
						}
					}if(minb<minc){
						b1[bi]=b[bi];
						a1[bi]=0;
					}else{
						c1[ci]=c[ci];
						a1[ci]=0;
					}anum--;
				}
			}else if(bnum>n/2){
				while(bnum>n/2){
					long long mina=0xf777,minc=0xf777,ai=0,ci=0;
					for(long long i=1;i<=n;i++){
						if(axt[i]==1&&bxt[i]==1&&cxt[i]==1)continue;
						if(b1[i]){
							if(mina>adc[i]){
								mina=adc[i];
								ai=i;
							}if(minc>cdc[i]){
								minc=cdc[i];
								ci=i;
							}
						}
					}if(mina<minc){
						a1[ai]=a[ai];
						b1[ai]=0;
					}else{
						c1[ci]=c[ci];
						b1[ci]=0;
					}bnum--;
				}
			}else if(cnum>n/2){
				while(cnum>n/2){
					long long mina=0xf777,minb=0xf777,ai=0,bi=0;
					for(long long i=1;i<=n;i++){
						if(axt[i]==1&&bxt[i]==1&&cxt[i]==1)continue;
						if(c[i]){
							if(minb>bdc[i]){
								minb=bdc[i];
								bi=i;
							}if(mina>adc[i]){
								mina=adc[i];
								ai=i;
							}
						}
					}if(minb<mina){
						b1[bi]=b[bi];
						c1[bi]=0;
					}else{
						a1[ai]=a[ai];
						c1[ai]=0;
					}cnum--;
				}
			}for(int i=1;i<=n;i++){
				cout<<adc[i]<<" "<<bdc[i]<<" "<<cdc[i]<<endl;
			}for(int i=1;i<=n;i++){
				cout<<a1[i]<<" "<<b1[i]<<" "<<c1[i]<<endl;
			}
		}for(long long i=1;i<=n;i++){
			ans+=a1[i]+b1[i]+c1[i];
			if(axt[i]==1&&bxt[i]==1&&cxt[i]==1)ans+=a[i];
		}cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
