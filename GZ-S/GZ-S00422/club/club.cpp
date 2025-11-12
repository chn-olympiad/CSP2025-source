//GZ-S00422 赵其坤 遵义航天高级中学                                              
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[4][N];
int a1,a2,a3,ans;
void dfs(int x,int y,int cnt){
	if(y==n){
		ans=max(ans,cnt);
		return;
	}
		if(a1<n-a1){
	    	int ty=y+1;
	    	int tcnt=cnt+a[1][ty];
	    	a1++;
	    	dfs(1,ty,tcnt);
	    	a1--;
		}
		if(a2<n-a2){
	    	int ty=y+1;
	    	int tcnt=cnt+a[2][ty];
	    	a2++;
	    	dfs(2,ty,tcnt);
	    	a2--;
		}
	    if(a3<n-a3){
	    	int ty=y+1;
	    	int tcnt=cnt+a[3][ty];
	    	a3++;
	    	dfs(3,ty,tcnt);
	    	a3--;
		} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    	ans=0;
    	memset(a,0,sizeof(0));
        cin>>n;
	    for(int i=1;i<=n;i++)
	        cin>>a[1][i]>>a[2][i]>>a[3][i];
	    dfs(1,0,0);
		cout<<ans;
    }
	return 0;
}

