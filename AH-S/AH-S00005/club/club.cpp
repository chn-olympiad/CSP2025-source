#include<bits/stdc++.h>
using namespace std;
long long t,n,xz,ans=0,a1,as,b1,bs,c1,cs,nou;
bool flaga=1,flagb=1;
struct note{
    long long a=0,b=0,c=0;
    long long fir=0,cha=0;
};
bool cmp(note x,note y){
    return x.a>y.a;
}
bool cmpcha(note x,note y){
    return x.cha<y.cha;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;flaga=1;flagb=1;a1=0;b1=0;c1=0;as=0;bs=0;cs=0;
        cin>>n;
        note a[n+5];
        for(long long i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].a>=max(a[i].b,a[i].c)){
                a1++;
                as+=a[i].a;
                a[i].fir=1;
                if(a[i].b>=a[i].c){
                    a[i].cha=a[i].a-a[i].b;
                }
                else{
                    a[i].cha=a[i].a-a[i].c;
                }
            }
            else if(a[i].b>=max(a[i].a,a[i].c)){
                b1++;
                bs+=a[i].b;
                a[i].fir=2;
                if(a[i].a>=a[i].c){
                    a[i].cha=a[i].b-a[i].a;
                }
                else{
                    a[i].cha=a[i].b-a[i].c;
                }
            }
            else{
                c1++;
                cs+=a[i].c;
                a[i].fir=3;
                if(a[i].a>=a[i].b){
                    a[i].cha=a[i].c-a[i].a;
                }
                else{
                    a[i].cha=a[i].c-a[i].b;
                }
            }//abaaba
            if(a[i].b!=0||a[i].c!=0) flaga=0;
            if(a[i].c!=0) flagb=0;
        }
        xz=n/2;
        //shuru
        if(flaga){
            sort(a+1,a+n+1,cmp);
            for(long long i=1;i<=xz;i++) ans+=a[i].a;
            cout<<ans<<endl;
            continue;
        }//A
        /*if(n==2){
            cout<<max(a[1].a,a[2].a)+max(a[1].b,a[2].b)+max(a[1].c,a[2].c)<<endl;
            continue;
        }*/

        ans=as+bs+cs;
        //cout<<as<<endl;
        if(a1<=xz&&b1<=xz&&c1<=xz){
            cout<<ans<<endl;
            continue;
        }//1.xiaoxiaoxiao
        sort(a+1,a+n+1,cmpcha);
        if(a1>=xz){
            nou=a1-xz;
            for(long long i=1;i<=n;i++){
                if(a[i].fir==1){
                    nou--;
                    ans-=a[i].cha;
                }
                if(nou==0) break;
            }
            cout<<ans<<endl;
            continue;
        }
        else if(b1>=xz){
            nou=b1-xz;
            for(long long i=1;i<=n;i++){
                if(a[i].fir==2){
                    nou--;
                    ans-=a[i].cha;
                }
                if(nou==0) break;
            }
            cout<<ans<<endl;
            continue;
        }
        else{
            nou=c1-xz;
            for(long long i=1;i<=n;i++){
                if(a[i].fir==3){
                    nou--;
                    ans-=a[i].cha;
                }
                if(nou==0) break;
            }
            cout<<ans<<endl;
            continue;
        }//2.chaoxiaoxiao

    }

    return 0;
}
