#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=1e5+6;

LL T,n,m,sum,cnt,ans;
LL A[N],C[N];

struct hp{
	LL lp,pl;
};

bool cmp(hp x,hp y){
	return x.lp>y.lp;
}

struct op{
	hp op[4];
	LL idx=0;
	void readr(){
		cin>>op[1].lp>>op[2].lp>>op[3].lp;
		for(int i=1;i<=3;i++)op[i].pl=i;
		sort(op+1,op+3+1,cmp);
		idx=0;
		for(int i=1;i<=3;i++){
			if(op[i].lp==op[1].lp)idx|=(1<<(op[i].pl-1));
		}
		return ;
	}
}B[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			B[i].readr();
		}
		ans=0;
		for(int i=1;i<=n;i++){
			A[B[i].idx]++;ans+=(B[i].op[1]).lp;
		}
		for(int i=1;i<=3;i++){
			if(A[(1<<(i-1))]>n/2){
				cnt=0;
				for(int j=1;j<=n;j++){
					if(B[j].idx==(1<<(i-1))){
						C[++cnt]=((B[j].op[1]).lp)-((B[j].op[2]).lp);
					}
				}
				sort(C+1,C+cnt+1);
				for(int j=1;j+n/2<=A[(1<<(i-1))];j++){
					ans-=C[j];
				}
				break;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			A[B[i].idx]=0;
		}
	}
	
	return 0;
}
