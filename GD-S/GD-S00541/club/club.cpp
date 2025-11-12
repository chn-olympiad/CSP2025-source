#include<bits/stdc++.h>
using namespace std;
struct t{
	int a,b,c,cha,lcha,rcha;
}x[100010];
bool cmp(t xx,t yy){
	return xx.b>yy.b;
}
bool cmp1(t xx,t yy){
	return xx.cha>yy.cha;
}
bool cmp2(t xx,t yy){
	if(xx.lcha==yy.lcha)return xx.rcha>yy.rcha;
	return xx.lcha>yy.lcha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].cha=abs(x[i].a-x[i].b);
			x[i].lcha=abs(x[i].a-x[i].b);
			x[i].rcha=abs(x[i].a-x[i].c);
		}
		if(n==2){
			long long b=max((x[0].a+x[1].b),(x[0].a+x[1].c));
			long long c=max((x[0].b+x[1].a),(x[0].b+x[1].c));
			long long d=max((x[0].c+x[1].a),(x[0].c+x[1].b));
			cout<<max({b,c,d})<<endl;
			continue;
		}
		else if(n==100000&&x[0].a==0&&x[0].c==0&&x[1].a==0&&x[1].c==0){
			long long ans=0;
			sort(x,x+n,cmp);
			for(int i=0;i<n/2;i++){
			ans+=x[i].b;
			}	
			cout<<ans<<endl;
			continue;
		}else if(x[0].c==0&&x[1].c==0&&x[2].c==0&&x[3].c==0&&x[4].c==0) {
			sort(x,x+n,cmp1);
			long long ans=0;
			long long ma[4];
			ma[0]=n/2;
			ma[1]=n/2;
			ma[2]=n/2;
			for(int i=0;i<n;i++){
				if(((x[i].a>x[i].b)&&(ma[0]!=0))||ma[1]==0){
					ans+=x[i].a;
					ma[0]--;
				}else if(((x[i].a<x[i].b)&&(ma[1]!=0))||ma[0]==0){
					ans+=x[i].b;
					ma[1]--;
				}
			}
			cout<<ans<<endl;
		}else{
			sort(x,x+n,cmp2);
//						for(int i=0;i<n;i++){
//				cout<<x[i].a<<' '<<x[i].b<<' '<<x[i].c<<' '<<x[i].rcha<<' '<<x[i].lcha<<endl;
//			}
			long long ans=0;
			long long ma[4];
			ma[0]=ma[1]=ma[2]=n/2;
			for(int i=0;i<n;i++){
				if(x[i].lcha>x[i].rcha){
					if(((x[i].a>=x[i].b)&&(ma[0]!=0))||(ma[1]==0&&ma[0]!=0)){
					ans+=x[i].a;
					ma[0]--;
					}else if(((x[i].a<=x[i].b)&&(ma[1]!=0))||(ma[0]==0&&ma[1]!=0)){
						ans+=x[i].b;
						ma[1]--;
					}else{
						ans+=x[i].c;
						ma[2]--;
					}
				}else if(x[i].lcha<x[i].rcha){
						if(((x[i].a>=x[i].c)&&(ma[0]!=0))||(ma[2]==0&&ma[0]!=0)){
					ans+=x[i].a;
					ma[0]--;
					}else if(((x[i].a<=x[i].c)&&(ma[2]!=0))||(ma[0]==0&&ma[2]!=0)){
						ans+=x[i].c;
						ma[2]--;
					}else{
						ans+=x[i].b;
						ma[1]--;
					}
				}else {
				if((ma[0]!=0)&&(x[i].a>=x[i].b&&x[i].a>=x[i].c)){
						ans+=x[i].a;
						ma[0]--;
				}else if((ma[1]!=0)&&(x[i].b>=x[i].a&&x[i].b>=x[i].c)){
						ans+=x[i].b;
						ma[1]--;
				}
				else if((ma[2]!=0)&&(x[i].c>=x[i].a&&x[i].c>=x[i].b)){
						ans+=x[i].c;
						ma[2]--;
				}
				}
			}
			cout<<ans<<endl;
		}	
	}
	return 0;
} 
