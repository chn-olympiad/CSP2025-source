#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int fi,se,tr;
    int num;
}a[N];
node b[N],c[N];
int t,n;
int club1,club2,d;
bool cmp1(node A,node B){
    return  A.fi>B.fi;
}
bool cmp2(node A,node B){
    return  A.se>B.se;
}
int ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    club1=club2=ans=0;
       scanf("%d",&n);
       for(int i=1;i<=n;i++){
                scanf("%d%d%d",&a[i].fi,&a[i].se,&a[i].tr);
                b[i].num=c[i].num=a[i].num=i;
                b[i].fi=a[i].fi;
                b[i].se=a[i].se;
                c[i].fi=a[i].fi;
                c[i].se=a[i].se;
       }
       sort(b+1,b+n+1,cmp1);
       sort(c+1,c+n+1,cmp2);
       int i=0;
       for(int i=1;i<=n;i++){
            if(b[i].num!=c[i].num){
            if(club1<n/2){
                    ans+=b[i].fi;
                    club1++;

                }
                if(club2<n/2){
                    ans+=c[i].se;

                    club2++;
                }
            }else{

                if(b[i].fi>c[i].se&&club1<n/2){
                    ans+=b[i].fi;
                    club1++;

                }else if(club2<n/2){
                    ans+=c[i].se;
                    club2++;
                }
            }
       }
    printf("%d\n",ans);
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int fi,se,tr;
}a[N];
int b[N];
bool cmp(int A,int B){
    return  A>B;
}
int n,t;
int ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].fi,&a[i].se,&a[i].tr);
            b[i]=a[i].fi;
        }
        sort(b+1,b+n+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=b[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}*/
