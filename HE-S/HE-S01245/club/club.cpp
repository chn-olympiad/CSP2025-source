#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,ans,clc;
int hn;
struct node{
	int a,b,c;
	int m,max_;
}stu[100010];
int min_[100010];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		clc=0;
		scanf("%lld",&n);
		hn=n/2;
		int ma=0,mb=0,mc=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&stu[i].a,&stu[i].b,&stu[i].c);
			stu[i].max_=max( stu[i].a, max( stu[i].b,stu[i].c) );
			ans+=stu[i].max_;
			if(stu[i].max_==stu[i].a){
				stu[i].m=1;
				ma++;
			}
			else if(stu[i].max_==stu[i].b){
				stu[i].m=2;
				mb++;
			} 
			else {
				stu[i].m=3;
				mc++;
			}
		}	
		if(ma>hn){
			for(int i=1;i<=n;i++){
				if(stu[i].m==1){
					clc++;
					min_[clc]=stu[i].a-(max(stu[i].b,stu[i].c));
				}
			}
			sort(min_+1,min_+clc+1,cmp);
			for(int i=clc;i>hn;i--){
				ans-=min_[i];
			}
		}
		else if(mb>hn){
			for(int i=1;i<=n;i++){
				if(stu[i].m==2){
					clc++;
					min_[clc]=stu[i].b-(max(stu[i].a,stu[i].c));
				}
			}
			sort(min_+1,min_+clc+1,cmp);
			for(int i=clc;i>hn;i--){
				ans-=min_[i];
			}
		}
		else if(mc>hn){
			for(int i=1;i<=n;i++){
				if(stu[i].m==3){
					clc++;
					min_[clc]=stu[i].c-(max(stu[i].a,stu[i].b));
				}
			}
			sort(min_+1,min_+clc+1,cmp);
			for(int i=clc;i>hn;i--){
				ans-=min_[i];
			}
		}
		printf("%lld\n",ans);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

147325

*/
