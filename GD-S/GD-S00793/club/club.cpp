#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,an[2000008],anss[20000080],dp[200008][8],p[208];
struct tt{
	int a,b,c;
}d[20000008];
int cmp(tt i,tt j){
	return i.a >j.a ;
}
int cmp2(tt i,tt j){
	return i.a +j.b >i.b +j.a ;
}
int cmp3(tt i,tt j){
	if(i.a +i.b +i.c ==j.a +j.b +j.c &&max(i.a ,max(i.b ,i.c ))==max(j.a ,max(j.b ,j.c ))){
		int tt1=min(i.a ,min(i.b ,i.c )),tt2=min(j.a ,min(j.b ,j.c ));
		int kk1=max(i.a ,max(i.b ,i.c )),kk2=max(j.a ,max(j.b ,j.c ));
		//return (i.a !=tt1&&i.a !=kk1)*i.a +(i.b !=tt1&&i.b !=kk1)*i.b+(i.c !=tt1&&i.c !=kk1)*i.c>(j.a !=tt1&&j.a !=kk1)*j.a +(j.b !=tt1&&j.b !=kk1)*j.b+(j.c !=tt1&&j.c !=kk1)*j.c;
		return min(i.a ,min(i.b ,i.c ))<min(j.a ,min(j.b ,j.c ));
	} 
	if(i.a +i.b +i.c ==j.a +j.b +j.c ) return max(i.a ,max(i.b ,i.c ))>max(j.a ,max(j.b ,j.c ));
	return i.a +i.b +i.c <j.a +j.b +j.c ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		k=n/2,ans=0;
		int pd1=0,pd2=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].a >>d[i].b >>d[i].c ;
			dp[i][1]=0,dp[i][2]=0,dp[i][3]=0;
			p[1]=0,p[2]=0,p[3]=0;
			if(d[i].b ==d[i].c ) pd1++;
			if(d[i].c ==0) pd2++;
		}
		if(pd1==n){
			sort(d+1,d+1+n,cmp);
			for(int i=1;i<=k;i++){
				ans+=d[i].a ;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(pd2==n){
			long long la=0;
			sort(d+1,d+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=k) ans=ans+d[i].a ;
				else ans=ans+d[i].b ;
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(d+1,d+1+n,cmp3);
		for(int i=1;i<=n;i++){
				if(d[i].a >d[i].b &&d[i].a >d[i].c ){
					if(p[1]+1<=k){
						ans=ans+d[i].a ;
						p[1]++;
					}
					else if(d[i].b >d[i].c &&p[2]+1<=k){
						ans=ans+d[i].b ;
						p[2]++;
					}	
					else{
						ans=ans+d[i].c ;
						p[3]++;
					}
				}	
				if(d[i].b >d[i].a &&d[i].b >d[i].c ){
					if(p[2]+1<=k){
						ans=ans+d[i].b ;
						p[2]++;
					}	
					else if(d[i].a >d[i].c &&p[1]+1<=k){
						ans=ans+d[i].a ;
						p[1]++;
					}
					else{
						ans=ans+d[i].c ;
						p[3]++;
					}
				}
				if(d[i].c >d[i].a &&d[i].c >d[i].b ){
					if(p[3]+1<=k){
						ans=ans+d[i].c ;
						p[3]++;
					}
					else if(d[i].a >d[i].b &&p[1]+1<=k){
						ans=ans+d[i].a ;
						p[1]++;
					}
					else{
						ans=ans+d[i].b ;
						p[2]++;
					}
				}
		}
		cout<<ans<<"\n";
	}
}
/*
1 9 3
8 12 3

*/
