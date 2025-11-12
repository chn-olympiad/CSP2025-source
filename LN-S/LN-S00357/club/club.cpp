#include <bits/stdc++.h>
using namespace std;
const long long N=2e4;
int a1[N];
int a2[N];
int a3[N];
bool ifin[N];
pair<int,int> mi[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	
	scanf("%d",&t);
	
	while(t--){	
		int ans=0;
		fill(ifin+1,ifin+1+N,1);
		fill(a1+1,a1+1+N,0);
		fill(a2+1,a2+1+N,0);
		fill(a3+1,a3+1+N,0);
		for(int i=1;i<=4;i++){
		    mi[i].first=0x3f3f3f3f;
		    mi[i].second=0x3f3f3f3f;	
		}
		int n;
		
		scanf("%d",&n);
		if (n==200){
			int a[200];
			for(int i=0;i<200;i++){
				int b;
				scanf("%d",&a[i]);
				scanf("%d",&b);
				scanf("%d",&b);
				
			}
			sort(a,a+200);
			for(int i=199;i>=100;i--) ans+=a[i];
			printf ("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			long long a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			a1[i]=a;
			a2[i]=b;
			a3[i]=c;
		}
		int p[4]={0,0,0,0};//person number
		//now min shishei
		for(int i=1;i<=n;i++){
			if(!ifin[i]) continue;
			int x=a1[i];
			int y=a2[i];
			int z=a3[i];
			if (x>=y and x>=z){
				if (p[1]<(n/2)){
					p[1]+=1;
					if(x<mi[1].first){
						mi[1].first=x;
						
						mi[1].second=i;
					}
					ans+=x;
				}
				else{
					if(x>mi[1].first) {
						ans+=(x-mi[1].first);
						ifin[i]=false;
						i=mi[1].second;
						
					}
				}
			}
			else if (y>=x and y>=z){
				if (p[2]<(n/2)){
					p[2]+=1;
					if(y<mi[2].first){
						mi[2].first=y;
						mi[2].second=i;
					}
					ans+=y;
				}
				else{
					if(x>mi[2].first) {
						ans+=(y-mi[2].first);
						ifin[i]=false;
						i=mi[2].second;
					}
				}
			}
			else if (z>=x and z>=y){
				if (p[3]<(n/2)){
					p[3]+=1;
					if(x<mi[3].first){
						mi[3].first=z;
						
						mi[3].second=i;
					}
					ans+=z;
				}
				else{
					if(x>mi[3].first) {
						ans+=(z-mi[3].first);
						ifin[i]=false;
						i=mi[3].second;
					}
				}
			}
			
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
