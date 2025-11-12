#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int a,b,c;
	int cha;
	int p,q;
}e[100010];
int ans;
bool cmp(node x,node y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
		}
		for(int i=1;i<=n;i++){
			int mx1=0,mx2=0;
			int p,q;
			for(int j=1;j<=3;j++){
				if(j==1){
					if(e[i].a>=mx1){
						q=p;
						mx2=mx1;
						p=1;
						mx1=e[i].a;
					}
					else if(e[i].a>mx2)	 {
						mx2=e[i].a;
						q=1;
					}
				}
				
				if(j==2){
					if(e[i].b>=mx1){
						q=p;
						mx2=mx1;
						p=2;
						mx1=e[i].b;
					}
					else	if(e[i].b>mx2){
						mx2=e[i].b;
						q=2;
					}
				}
				
				if(j==3){
					if(e[i].c>=mx1){
						q=p;
						mx2=mx1;
						p=3;
						mx1=e[i].c;
					}
					else  if(e[i].c>mx2) {
						mx2=e[i].c;
						q=3;	
					}
				}
			}
			e[i].cha=mx1-mx2;
			e[i].p=p;
			e[i].q=q;
		}
		sort(e+1,e+1+n,cmp);
		int A=0,B=0,C=0;
//		for(int i=1;i<=n;i++){
//			cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].c<<" "<<e[i].p<<" "<<e[i].q<<"\n";
//		}
		
		for(int i=1;i<=n;i++){
//			cout<<ans<<" ";
				if(e[i].p==1){
//					cout<<'a';
					if(A+1<=n/2){
					ans+=e[i].a;
					A++;
				}
				else{
					if(e[i].q==2){
						ans+=e[i].b;
						B++;
					}
					if(e[i].q==3){
						ans+=e[i].c;
						C++;
					}
				}
				}
				if(e[i].p==2){
//					cout<<'b';
					if(B+1<=n/2){
					ans+=e[i].b;
					B++;
				}
				else{
					if(e[i].q==1){
						ans+=e[i].a;
						A++;
					}
					if(e[i].q==3){
						ans+=e[i].c;
						C++;
					}
				}
				}
				
				if(e[i].p==3){
//					cout<<'c';
					if(C+1<=n/2){ans+=e[i].c;C++;}
				else{
					if(e[i].q==1){
						A++;
						ans+=e[i].a;
					}
					if(e[i].q==2){
						B++;
						ans+=e[i].b;
					}
				}
				}
		}
		printf("%d\n",ans);
//		for(int i=1;i<=n;i++){
//			for(int )
//		}
	}
	return 0;
} 
