#include<bits/stdc++.h>
#define int1 int
#define int long long
using namespace std;
const int N=100005;
int T,n;
int a1[N],a2[N],a3[N];
int ii,iii,iiii;
int1 q1,q2,q3;
int ans=0,maxn=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=q1=q2=q3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&ii,&iii,&iiii);
			maxn=max(ii,max(iii,iiii));
			if(maxn==ii){
				a1[++q1]=ii-max(iii,iiii);
			}
			else if(maxn==iii){
				a2[++q2]=iii-max(ii,iiii);
			}
			else if(maxn==iiii){
				a3[++q3]=iiii-max(ii,iii);
			}
			ans+=maxn;
		}
		int1 i=0;
		if(q1>n/2){
			stable_sort(a1+1,a1+q1+1);
			while(q1-i>n/2){
				i++;
				ans-=a1[i];
			}
		}
		else if(q2>n/2){
			stable_sort(a2+1,a2+q2+1);
			while(q2-i>n/2){
				i++;
				ans-=a2[i];
			}
		}
		else if(q3>n/2){
			stable_sort(a3+1,a3+q3+1);
			while(q3-i>n/2){
				i++;
				ans-=a3[i];
			}
		}
		printf("%lld\n",ans);
	}	
} 
