#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N][5];
bool vis[N];
int e[5];
long long ans;
struct op{
    int h,b,l,r;
    bool operator<(op &X)const{
		if(r!=X.r)return r>X.r;
        else return b>X.b;
    }
}p[N<<2];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++)vis[i]=0;
        e[1]=e[2]=e[3]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
        }
        ans=0;
        for(int i=1;i<=n;i++){
            int x=a[i][1],y=a[i][2],z=a[i][3];
            int maxn=x<y?y:x;
            int q=x<y?2:1;
            q=maxn<z?3:q;
            maxn=maxn<z?z:maxn;
            int minn;
            if(q==1)minn=y<z?z:y;
            if(q==2)minn=x<z?z:x;
            if(q==3)minn=x<y?y:x;
            //cout<<q<<endl;
            p[i].b=maxn;
            p[i].h=minn;
            p[i].l=q;
            p[i].r=maxn-minn;
        }
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++){
			if(e[p[i].l]<n/2){
				ans+=p[i].b;
				e[p[i].l]++;
			}else ans+=p[i].h;
			
		}
        printf("%lld\n",ans);
    }
    return 0;
}
