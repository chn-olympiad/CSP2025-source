#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const ull N = 1e5+5;

int t,n,res,sum,cnt,dp[5];

struct node{
	int a,b,c;
	bool operator<(const node& y){
		int x[3]={a,b,c},yy[3]={y.a,y.b,y.c};
		std::sort(x,x+3);
		std::sort(yy,yy+3);
		if(x[2]-x[1]==yy[2]-yy[1]){
			return x[1]-x[0]>yy[1]-yy[0];
		}
		return x[2]-x[1]>yy[2]-yy[1];
	}
}l[N];

signed main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	std::cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		res=0;
		
		std::cin>>n;
		for(int i=1;i<=n;i++){
			std::cin>>l[i].a>>l[i].b>>l[i].c;
		}
		
		std::sort(l+1,l+1+n);
		
		for(int i=1,jj;i<=n;i++){
			sum=cnt=0;
			if(l[i].a>sum){
				sum=l[i].a;
				jj=0;cnt=1;
			}
			if(l[i].b==sum){
				cnt++;
			}
			if(l[i].b>sum){
				sum=l[i].b;
				jj=1;cnt=1;
			}
			if(l[i].c==sum){
				cnt++;
			}
			if(l[i].c>sum){
				sum=l[i].c;
				jj=2;cnt=1;
			}
			if(dp[jj]>=n/2){
//				std::cout<<sum<<" "<<cnt<<"\n";
				if(cnt>=2){
					if(l[i].c==sum){
						dp[1]++;
					}
					else{
						dp[2]++;
					}
					res+=sum;
				}
				else{
					int tot=sum;
					sum=0;
					if(l[i].a>sum&&tot!=l[i].a){
						sum=l[i].a;
						jj=0;
					}
					if(l[i].b>sum&&tot!=l[i].b){
						sum=l[i].b;
						jj=1;
					}
					if(l[i].c>sum&&tot!=l[i].c){
						sum=l[i].c;
						jj=2;
					}
					dp[jj]++;
					res+=sum;
				}
			}
			else {
				dp[jj]++;
				res+=sum;
			}
		}
		
		std::cout<<res<<"\n";
	}
	
	return 0;
}