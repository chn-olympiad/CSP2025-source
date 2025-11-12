#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 1e5+5;
int t,n;
int t_a[MAXN],t_b[MAXN],ttb,t_c[MAXN],ttc;
int an,bn,cn;
int tmp[MAXN];
int maex;
int ans;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans = 0;
		an = 0,bn = 0,cn = 0;
		cin>>n;
		maex = n/2;
		for(int i = 1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			int maxes = max(max(a,b),c);
			if(maxes == a){
				int tc = min(maxes-b,maxes-c);
				t_a[++an] = tc;
			}
			else if(maxes == b){
				int tc = min(maxes-a,maxes-c);
				t_b[++bn] = tc;
			}
			else{
				int tc = min(maxes-b,maxes-a);
				t_c[++cn] = tc;
			}
			
			ans+=maxes;
		}
		if(an>maex){
			int cha = an-maex;
			sort(t_a+1,t_a+an+1);
			for(int i = 1;i<=cha;i++){
				ans-=t_a[i];
			}
		}
		if(bn>maex){
			int cha = bn-maex;
			sort(t_b+1,t_b+bn+1);
			for(int i = 1;i<=cha;i++){
				ans-=t_b[i];
			}
		}
		if(cn>maex){
			int cha = cn-maex;
			sort(t_c+1,t_c+cn+1);
			for(int i = 1;i<=cha;i++){
				ans-=t_c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
