#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,x,id;
}x[300005];
long long n,m,t,cnta,cntb,cntc,ans;
bool cmp(const node &x,const node &y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=cnta=cntb=cntc=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i].a);
			scanf("%lld",&x[i].b);
			scanf("%lld",&x[i].c);
			if(x[i].a==max(x[i].c,max(x[i].a,x[i].b))){
				cnta++;
			}else if(x[i].b==max(x[i].c,max(x[i].a,x[i].b))){
				cntb++;
			}else{
				cntc++;
			}
			x[i].id=i;
		}
		//cout<<cnta<<" "<<cntb<<" "<<cntc<<endl;
		if(cnta>=cntb and cnta>=cntc){
			for(int i=1;i<=n;i++){
				x[i].x=x[i].a-max(x[i].b,x[i].c);
			}
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=min(cnta,n/2);i++){
				if(x[i].x>=0){
					ans+=x[i].a;
				}
			}
			for(int i=min(cnta,n/2)+1;i<=n;i++){
				
				ans+=max(x[i].b,x[i].c);
			}
		}else if(cntb>=cnta and cntb>=cntc){
			for(int i=1;i<=n;i++){
				x[i].x=x[i].b-max(x[i].a,x[i].c);
			}
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=min(cntb,n/2);i++){
				if(x[i].x>0){
					ans+=x[i].b;
				}
			}
			for(int i=min(cntb,n/2)+1;i<=n;i++){
				
					ans+=max(x[i].a,x[i].c);
			}
		}else{
			for(int i=1;i<=n;i++){
				x[i].x=x[i].c-max(x[i].a,x[i].b);
			}
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=min(cntc,n/2);i++){
				if(x[i].x>0){
					ans+=x[i].c;
				}
			}
			for(int i=min(cntc,n/2)+1;i<=n;i++){
				
					ans+=max(x[i].a,x[i].b);
			}
		}
		printf("%.lld\n",ans);
	}
	
	return 0;
}
