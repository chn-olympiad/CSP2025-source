#include<iostream>
using namespace std;
int n,k,sum[500005],pos[1050000];
bool vis[1050000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int x;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		sum[i]=sum[i-1]^x;
	}
	int ans=0,j=-1;
	vis[0]=true;
	pos[0]=0;
	for(int i=1;i<=n;i++){
		if(vis[(sum[i]^k)]==1&&pos[(sum[i]^k)]>=j){
			j=i;
			ans++;
		}
		pos[sum[i]]=i;
		vis[sum[i]]=true;
	}
	cout<<ans;
	return 0;
}
//csp-s rp++
/*
RRRRRRR        PPPPPPP
RRRRRRRRR      PPPPPPPPP
RR     RR      PP	  PP	++	   ++	
RR     RR	   PP     PP	++     ++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRR 		   PP			++     ++
RRRRR		   PP			++     ++
RR RRR		   PP	
RR  RRR		   PP
RR   RRR	   PP
RR    RRR 	   PP 
*/ 
