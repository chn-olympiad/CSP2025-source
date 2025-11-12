#include<bits/stdc++.h>
using namespace std;

const int P=998244353;
int n,a[5010];
struct node{
	int a,b,c,d;
};
map<node,int> f;

int dfs(int i,int sum,int ma,int cnt){
    if(i==n+1){
        if(cnt>=3){
            return sum>2*ma;
        }
        return 0;
    }
    if(f[{i,sum,ma,cnt}]){
		return f[{i,sum,ma,cnt}];
	}
    int x=dfs(i+1,sum,ma,cnt)%P;
    x=(x+dfs(i+1,sum+a[i],max(ma,a[i]),cnt+1))%P;
    f[{i,sum,ma,cnt}]=x;
    return f[{i,sum,ma,cnt}];
}

int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",dfs(1,0,INT_MIN,0));
}
