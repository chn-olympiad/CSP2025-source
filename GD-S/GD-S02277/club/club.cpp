#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct num{
	long long amx,amd;
	int idx,idd;
}a[100005];
int t,n;
bool cmb(num tx,num ty){
	if(tx.amx-tx.amd==ty.amx-ty.amd)return tx.amx>ty.amx;
	else return (tx.amx-tx.amd>ty.amx-ty.amd);
}
long long s[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i=i+1){
			long long tx,ty,tz;
			scanf("%lld%lld%lld",&tx,&ty,&tz);
			if(tx>ty&&tx>tz){
				a[i].amx=tx;
				a[i].idx=1;
				if(ty>tz){a[i].amd=ty;a[i].idd=2;}
				else{a[i].amd=tz;a[i].idd=3;}
			//max-tx
			}
			else if(ty>tx&&ty>tz){
				a[i].amx=ty;
				a[i].idx=2;
				if(tx>tz){a[i].amd=tx;a[i].idd=1;}
				else{a[i].amd=tz;a[i].idd=3;}
			//max-ty
			}
			else if(tz>ty&&tz>tx){
				a[i].amx=tz;
				a[i].idx=3;
				if(tx>ty){a[i].amd=tx;a[i].idd=1;}
				else{a[i].amd=ty;a[i].idd=2;}
			//max-tz
			}
		//input
		}
		sort(a+1,a+n+1,cmb);
		long long ans=0;
		for(int i=1;i<=n;i=i+1){
			if(s[a[i].idx]>=n/2){
				s[a[i].idd]=s[a[i].idd]+1;
				ans=ans+a[i].amd;
			//add-sec
			}
			else{
				s[a[i].idx]=s[a[i].idx]+1;
				ans=ans+a[i].amx;
			//add-max
			}
		//each-add
		}
		printf("%lld\n",ans);
	//for-each-group
	}
	return 0;
//end--
} 
