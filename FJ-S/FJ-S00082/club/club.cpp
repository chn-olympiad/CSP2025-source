#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int t;
int n;
int a[N][4],k,club[4];
bool pe[N];
long long ans;

struct node{
	int v,p,cl;
}b[4*N];

void dfs(int q,long long sum){;
	if(q>n){
		ans = max(ans,sum);
		return;
	}
	for(int i = 1;i<=k;i++){
		if(club[b[i].cl] == n/2){
			continue;
		}
		if(pe[b[i].p]){
			continue;
		}
		club[b[i].cl]++;
		pe[b[i].p] = 1;
		dfs(q+1,sum+b[i].v);
		club[b[i].cl]--;
		pe[b[i].p] = 0;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	ans = 0;
    	k = 0;
    	for(int i = 1;i<=n;i++){
    		for(int j = 1;j<=3;j++){
    			scanf("%d",&a[i][j]);
    			b[++k].v = a[i][j];
    			b[k].p = i;
    			b[k].cl = j;
			}
		}
		dfs(1,0);
		printf("%d",ans);
		if(t != 0){
			puts("");
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
