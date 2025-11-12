#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=1e5+10;
int a[N][4];
int b[N];
int n,t;
int ans;
void dfs(int depth,int sum1,int sum2,int sum3,int sum){
    if(sum1>(n/2)||sum2>(n/2)||sum3>(n/2))return ;
    if(depth==n+1){
        ans=max(ans,sum);
        return ;
    }
    if(a[depth][0])dfs(depth+1,sum1+1,sum2,sum3,sum+a[depth][0]);
    if(a[depth][1])dfs(depth+1,sum1,sum2+1,sum3,sum+a[depth][1]);
    if(a[depth][2])dfs(depth+1,sum1,sum2,sum3+1,sum+a[depth][2]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        bool flga=1;
        for(int i=1;i<=n;i++){
            a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
            b[i]=a[i][0];
            if(a[i][1]==a[i][2]&&a[i][2]==0)flga=0;
	    }
        ans=0;
        if(!flga){
	        dfs(1,0,0,0,0);
    	    printf("%lld\n",ans);
		}else{
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2;i--)
				ans+=b[i];
			printf("%lld\n",ans);
		}
    }
    return 0;
}
