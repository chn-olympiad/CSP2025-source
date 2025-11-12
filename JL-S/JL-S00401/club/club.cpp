#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,c1[N],c2[N],c3[N],ans;
int maxx(int x,int y){return (x>y?x:y);}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);int n2=n/2;
        c1[0]=0,c2[0]=0,c3[0]=0,ans=0;
        for(int i=1;i<=n;i++){
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            int t=maxx(a,maxx(b,c));ans+=t;
            if(t==a) c1[0]++,c1[c1[0]]=maxx(b-a,c-a);
            else if(t==b) c2[0]++,c2[c2[0]]=maxx(a-b,c-b);
            else c3[0]++,c3[c3[0]]=maxx(a-c,b-c);
        }
        if(c1[0]>n2){
            sort(c1+1,c1+c1[0]+1);
            for(int i=c1[0];i>n2;i--) ans+=c1[i];
        }
        else if(c2[0]>n2){
            sort(c2+1,c2+c2[0]+1);
            for(int i=c2[0];i>n2;i--) ans+=c2[i];
        }
        else if(c3[0]>n2){
            sort(c3+1,c3+c3[0]+1);
            for(int i=c3[0];i>n2;i--) ans+=c3[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}