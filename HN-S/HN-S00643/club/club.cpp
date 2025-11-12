#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int loe,lto,lte;
long long ans;
int mi,iss;
struct Info{
	int z,x,c;
	int zx,zc,xc;
}a[100100];
bool cmp1(Info A,Info B){
	return A.zx<=B.zx;
}
bool cmp2(Info A,Info B){
	return A.zc<=B.zc;
}
bool cmp3(Info A,Info B){
	return A.xc<=B.xc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int w=1;w<=t;w++){
		scanf("%d",&n);
		vector<Info>onee,twoo,threee;
		loe=0;
		lto=0;
		lte=0;
		ans=0;
		Info zero;
		zero.z=zero.x=zero.c=0;
		zero.zx=zero.zc=zero.xc=0;
		onee.push_back(zero);
		twoo.push_back(zero);
		threee.push_back(zero);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].z,&a[i].x,&a[i].c);
			a[i].zx=min(abs(a[i].z-a[i].x),abs(a[i].z-a[i].c));
			a[i].zc=min(abs(a[i].x-a[i].z),abs(a[i].x-a[i].c));
			a[i].xc=min(abs(a[i].c-a[i].z),abs(a[i].c-a[i].x));
			if(a[i].z>=a[i].x&&a[i].z>=a[i].c){
				onee.push_back(a[i]);
				++loe;
				ans+=a[i].z;
			}else if(a[i].x>=a[i].z&&a[i].x>=a[i].c){
				twoo.push_back(a[i]);
				++lto;
				ans+=a[i].x;
			}else if(a[i].c>=a[i].z&&a[i].c>=a[i].x){
				threee.push_back(a[i]);
				++lte;
				ans+=a[i].c;
			}else{
				printf("RP++\n");
			}
		}
		if(loe>n/2){
			sort(onee.begin()+1,onee.begin()+loe+1,cmp1);
			for(int i=1;i<=loe-n/2;i++){
				ans-=onee[i].zx;
			}
		}else if(lto>n/2){
			sort(twoo.begin()+1,twoo.begin()+lto+1,cmp2);
			for(int i=1;i<=lto-n/2;i++){
				ans-=twoo[i].zc;
			}
		}else if(lte>n/2){
			sort(threee.begin()+1,threee.begin()+lte+1,cmp3);
			for(int i=1;i<=lte-n/2;i++){
				ans-=threee[i].xc;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
15:14过第一组样例 
15:15过第二组样例
15:16五组样例全过 
*/
