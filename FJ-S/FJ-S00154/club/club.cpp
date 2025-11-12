#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int a,b,c,maxn=-1e9;
}p[N];
bool cmp(node af,node bf){
	return af.a>bf.a;
}
int aa,bb,cc,dp[N],aaa[N],bbb[N],ccc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ct=0,ctt=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		for(int i=1;i<=n;i++){
			if(p[i].b==0) ct++;
			if(p[i].c==0) cc++;
		}
		if(ct==n&&ctt==n){
			int x=n/2;
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(x>0){
					sum+=p[i].a;
					x--; 
				}
			}
			cout<<sum<<endl;
		}
		else{
			int x=n/2;
			for(int i=1;i<=n;i++){
				if(aa<x&&bb<x&&cc<x){
					int xx=dp[i-1]+p[i].a;
					int yy=dp[i-1]+p[i].b;
					int zz=dp[i-1]+p[i].c;
					if(yy>xx&&yy>zz){
						dp[i]=yy;
						bb++;
					}
					else if(xx>yy&&xx>zz){
						dp[i]=xx;
						aa++;
					}
					else if(zz>yy&&zz>xx){
						dp[i]=zz;
						cc++;
					}
				}
				else if(aa>=x&&bb<x&&cc<x){
					int yy=dp[i-1]+p[i].b;
					int zz=dp[i-1]+p[i].c;
					if(yy>zz){
						dp[i]=yy;
						bb++;
					}
					else{
						dp[i]=zz;
						cc++;
					}
				}	
				else if(aa<x&&bb>=x&&cc<x){
					int xx=dp[i-1]+p[i].a;
					int zz=dp[i-1]+p[i].c;
					if(xx>zz){
						dp[i]=xx;
						aa++;
					}
					else{
						dp[i]=zz;
						cc++;
					}
				}	
				else if(aa<x&&bb<x&&cc>=x){
					int yy=dp[i-1]+p[i].b;
					int xx=dp[i-1]+p[i].a;
					if(yy>xx){
						dp[i]=yy;
						bb++;
					}
					else{
						dp[i]=xx;
						aa++;
					}
				}	
				else if(aa>=x&&bb>=x&&cc<x){
					int zz=dp[i-1]+p[i].c;
					dp[i]=zz;
				}	
				else if(aa>=x&&bb<x&&cc>=x){
					int yy=dp[i-1]+p[i].b;
					dp[i]=yy;
				}		
				else if(aa<x&&bb>=x&&cc>=x){
					int xx=dp[i-1]+p[i].a;
					dp[i]=xx;
				}
			}
			int k=dp[n];
			aa=0;
			bb=0;
			cc=0;
			for(int i=1;i<=n;i++) dp[i]=0;
			for(int i=n;i>=1;i--){
				aaa[n-i+1]=p[i].a;
				bbb[n-i+1]=p[i].b;
				ccc[n-i+1]=p[i].c;
			}
			for(int i=1;i<=n;i++){
				if(aa<x&&bb<x&&cc<x){
					int xx=dp[i-1]+aaa[i];
					int yy=dp[i-1]+bbb[i];
					int zz=dp[i-1]+ccc[i];
					if(yy>xx&&yy>zz){
						dp[i]=yy;
						bb++;
					}
					else if(xx>yy&&xx>zz){
						dp[i]=xx;
						aa++;
					}
					else if(zz>yy&&zz>xx){
						dp[i]=zz;
						cc++;
					}
				}
				else if(aa>=x&&bb<x&&cc<x){
					int yy=dp[i-1]+bbb[i];
					int zz=dp[i-1]+ccc[i];
					if(yy>zz){
						dp[i]=yy;
						bb++;
					}
					else{
						dp[i]=zz;
						cc++;
					}
				}	
				else if(aa<x&&bb>=x&&cc<x){
					int xx=dp[i-1]+aaa[i];
					int zz=dp[i-1]+ccc[i];
					if(xx>zz){
						dp[i]=xx;
						aa++;
					}
					else{
						dp[i]=zz;
						cc++;
					}
				}	
				else if(aa<x&&bb<x&&cc>=x){
					int yy=dp[i-1]+bbb[i];
					int xx=dp[i-1]+aaa[i];
					if(yy>xx){
						dp[i]=yy;
						bb++;
					}
					else{
						dp[i]=xx;
						aa++;
					}
				}	
				else if(aa>=x&&bb>=x&&cc<x){
					int zz=dp[i-1]+ccc[i];
					dp[i]=zz;
				}	
				else if(aa>=x&&bb<x&&cc>=x){
					int yy=dp[i-1]+bbb[i];
					dp[i]=yy;
				}		
				else if(aa<x&&bb>=x&&cc>=x){
					int xx=dp[i-1]+aaa[i];
					dp[i]=xx;
				}
			}
			cout<<max(dp[n],k)<<endl;
			aa=0;
			bb=0;
			cc=0;
			for(int i=1;i<=n;i++){
				dp[i]=0;
			}
		}
	}
	return 0;
}
