#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,D=998244353;
char sr[N];
int n,m,a[N],as,q[N];
bool c[N];
void dfs(int x){
	int i;
	if(x>n){
		int sm=0;
		for(i=1;i<=n;++i){
			if(sr[i]=='0'){
				++sm;
			}
			else if(sm>=a[q[i]]){
				++sm;
			}
		}
		if(n-sm>=m){
			++as;
		}
	}	
	for(i=1;i<=n;++i){
		if(!c[i]){
			c[i]=1;
			q[x]=i;
			dfs(x+1);
			c[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,c1=1;
	scanf("%d%d",&n,&m);
	scanf("%s",sr+1);
	for(i=1;i<=n;++i){
		if(sr[i]=='0'){
			c1=0;
			break;
		}
	}
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	if(n<=10){
		dfs(1);
	    printf("%d",as);
	    return 0;
	}
	if(c1){
		as=1;
		for(i=2;i<=n;++i){
			as=(ll)as*(ll)i%D;
			//printf("%d ",as);
		}
		printf("%d",as);
		return 0;
	}
	return 0;
} 
