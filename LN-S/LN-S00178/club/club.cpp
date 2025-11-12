#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int MN=1e5+20;
struct club{
    i64 x[3],m1,m2,m,ans,id;
};
struct c2{
    i64 m,id;
};
i64 read(){
    i64 x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c-'0');
        c=getchar_unlocked();
    }
    return x*f;
}
void write(i64 p){
    if(p<0){
        putchar_unlocked('-');
        write(-p);
    }else if(p<10){
        putchar_unlocked(p+'0');
    }else{
        write(p/10);
        putchar_unlocked(p%10+'0');
    }
}
i64 max3a(i64 a,i64 b,i64 c){
    if(a>b){
        if(b>c){
            return 0;
        }else{
            if(a>c) return 0;
            else return 2;
        }
    }else{
        if(a>c){
            return 1;
        }else{
            if(b>c) return 1;
            else return 2;
        }
    }
}
i64 max3b(i64 a,i64 b,i64 c){
    if(a>b){
        if(b>c){
            return 1;
        }else{
            if(a>c) return 2;
            else return 0;
        }
    }else{
        if(a>c){
            return 0;
        }else{
            if(b>c) return 2;
            else return 1;
        }
    }
}
bool cmp(c2 a,c2 b){
    return a.m<b.m;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=read();
    while(t--){
        club a[MN];
        c2 cha[MN];
        int n=read(),cb[3]={0};
        for(int i=1;i<=n;i++){
            a[i].x[0]=read();
            a[i].x[1]=read();
            a[i].x[2]=read();
            a[i].m1=max3a(a[i].x[0],a[i].x[1],a[i].x[2]);
            cb[a[i].m1]++;
            a[i].m2=max3b(a[i].x[0],a[i].x[1],a[i].x[2]);
            a[i].ans=a[i].m1;
            a[i].m=a[i].x[a[i].m1]-a[i].x[a[i].m2];
            a[i].id=i;
        }
        int maxid=max3a(cb[0],cb[1],cb[2]),maxc=max(cb[0],max(cb[1],cb[2]));
        if(maxc>n/2){
            int j=1;
            for(int i=1;i<=n;i++){
                if(a[i].ans==maxid){
                    cha[j].m=a[i].m;
                    cha[j].id=a[i].id;
                    ++j;
                }
            }
            sort(cha+1,cha+j,cmp);
            for(int i=1;i<=maxc-n/2;i++){
               a[cha[i].id].ans=a[cha[i].id].m2;
            }
        }
        i64 sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+a[i].x[a[i].ans];
        }
        write(sum);
        putchar_unlocked('\n');
    }
    return 0;
}
