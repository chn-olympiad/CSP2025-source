#include<bits/stdc++.h>
#define int long long
const long long N=100050;
using namespace std;
struct node{
	int i,a,b,c,ma,cha,mx;
}in[N];
node in1[N],in2[N],in3[N];
int cmp(node a,node b){
	return a.cha>b.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int cnt[4]={0,0,0,0};
		scanf("%d",&n);
		int i1=0,i2=0,i3=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&in[i].a,&in[i].b,&in[i].c);
			in[i].i=i;
			in[i].ma=max(in[i].a,max(in[i].b,in[i].c));//10
			if(in[i].ma==in[i].a)in[i].mx=1;//1
			if(in[i].ma==in[i].b)in[i].mx=2;
			if(in[i].ma==in[i].c)in[i].mx=3;
			cnt[in[i].mx]++;//1
			in[i].cha=2*in[i].ma+min(in[i].a,min(in[i].b,in[i].c))-in[i].a-in[i].b-in[i].c;
			if(in[i].mx==1){in1[i1]=in[i];i1++;}
			if(in[i].mx==2){in2[i2]=in[i];i2++;}
			if(in[i].mx==3){in3[i3]=in[i];i3++;}
		}
		int ans=0;
			for(int i=0;i<n;i++){
				ans+=in[i].ma; 
			}
		if(max(cnt[1],max(cnt[2],cnt[3]))>n/2){
			if(cnt[1]>n/2){
				sort(in1,in1+cnt[1],cmp);
				for(int i=n/2;i<cnt[1];i++){
					ans-=in1[i].cha;
				}
			}
			else if(cnt[2]>n/2){
				sort(in2,in2+cnt[2],cmp);
				for(int i=n/2;i<cnt[2];i++){
					ans-=in2[i].cha;
				}
			}
			else if(cnt[3]>n/2){
				sort(in3,in3+cnt[3],cmp);
				for(int i=n/2;i<cnt[3];i++){
					ans-=in3[i].cha;
				}
			}
			cout<<ans<<endl;
		}
		else{
			
			cout<<ans<<endl;
		}
//		sort(in,in+n,cmp);
//		for(int i=0;i<n;i++){
//			cout<<in[i].cha<<' ';
//		}
//		cout<<endl;
	}
	
	return 0;
}


