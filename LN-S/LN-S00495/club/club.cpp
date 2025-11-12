#include <bits/stdc++.h>  
using namespace std;
typedef long long LL;
const int N=1e5+5;
LL ans;
int t,ax[N],ay[N],num1,num2,num3;
bool st;
struct info{
	int a1,a2,a3;
}mem[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(mem,0,sizeof(mem));
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&mem[i].a1,&mem[i].a2,&mem[i].a3);
		for(int i=1;i<=n;i++)ax[i]=mem[i].a1;
		for(int i=1;i<=n;i++)ay[i]=mem[i].a2;
		sort(ax+1,ax+n+1);
		reverse(ax+1,ax+n+1);
		sort(ay+1,ay+n+1);
		reverse(ay+1,ay+n+1);
		for(int i=1;i<=n;i++){
			if(ax[i]>=ay[i]&&num1<n/2){
				ans+=ax[i];
				num1++;
				st=1;
			}
			else if(ax[i]>=ay[i]&&num1>=n/2){
				ans+=ay[i];
				num2++;
			}
			if(ax[i]<ay[i]&&num2<n/2&&!st){
				ans+=ay[i];
				num2++;
			}
			else if(ax[i]<ay[i]&&num2>=n/2){
				ans+=ax[i];
				num1++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
	}
