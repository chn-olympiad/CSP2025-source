#include<bits/stdc++.h>
using namespace std;
int ca=20000,cb=20000,cc=20000;
int n,a,b,c,ra=0,rb=0,rc=0,cnt=0;
int aa[50000],ba[50000],ac[50000];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int m=0;
	scanf("%d",&m);
	while(m--){
		ca=20000,cb=20000,cc=20000,ra=0,rb=0,rc=0,cnt=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int t;
			scanf("%d%d%d",&a,&b,&c);
			if(a>b&&a>c){
				if(ra!=0)for(int i=0;i<ra;i++){
					ca=min(aa[i],ca);
				}
				cnt+=a;
				t=a-max(b,c);
				aa[ra++]=t;
				if(ra>n/2){
					if(ca<t){
						cnt-=ca;
						ca=t;
					}
					else cnt-=t;
				}
			}
			else if(b>a&&b>c){
				if(rb!=0) for(int i=0;i<rb;i++){
					cb=min(ba[i],cb);
				}
				cnt+=b;
				t=b-max(a,c);
				ba[rb++]=t;
				if(rb>n/2){
					if(cb<t){
						cnt-=cb;
						cb=t;
					}
					else cnt-=t;
				}
			}
			else{
				if(rc!=0)for(int i=0;i<rc;i++){
					cc=min(ac[i],c);
				}
				cnt+=c;
				t=c-max(b,a);
				ac[rc++]=t;
				if(rc>n/2){
					if(cc<t){
						cnt-=cc;
						cc=t;
					}
					else cnt-=t;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
