#include<bits/stdc++.h>
using namespace std;
int ans,x,y,z;
struct mun{
    int p;
    int a,b,c;
    char fir,se,th;
}num[110000];
bool cmpa(mun a,mun b){
    if(a.a!=b.a)return a.a>b.a;
    else if(a.b!=b.b)return a.b<b.b;
    else return a.c<b.c;
}
bool cmpb(mun a,mun b){
    if(a.b!=b.b)return a.b>b.b;
    else return a.c<b.c;
}
bool cmpc(mun a,mun b){
    return a.c>b.c;
}
void want(mun a){
    if(a.a>=a.b&&a.a>=a.c){
        a.fir='a';
        if(a.b>=a.c){
            a.se='b';
            a.th='c';
        }
        else{
            a.se='c';
            a.th='b';
        }
    }
    else if(a.b>a.a&&a.b>=a.c){
        a.fir='b';
        if(a.a>=a.c){
            a.se='a';
            a.th='c';
        }
        else{
            a.se='c';
            a.th='a';
        }
    }
    else{
        a.fir='c';
        if(a.a>=a.b){
            a.se='a';
            a.th='b';
        }
        else{
            a.se='b';
            a.th='a';
        }
    }
}
int main(){
    int n,s,t,y;
    freopen("club.in","w",stdin);
    freopen("club.out","r",stdout);
    scanf("%d",&s);
    for(int t=1;t<=s;t++){
        int i,j,k;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&num[i].a,&num[i].b,&num[i].c);
            num[i].p=i;
        }
        for(i=1;i<=n;i++){
                want(num[i]);
            if(num[i].fir=='a'){
                x++;
                ans+=num[i].a;
            }
            else if(num[i].fir=='b'){
                y++;
                ans+=num[i].b;
            }
            else{
                z++;
                ans+=num[i].c;
            }
        }
        if(max(max(x,y),z)==x){
            sort(num+1,num+n+1,cmpa);
            i=n;
            while(x>n/2){
                if(num[i].fir=='a'){
                    x--;
                    num[i].fir=num[i].se;
                    ans-=num[i].a;
                    if(num[i].fir=='b'){
                        ans+=num[i].b;
                        y++;
                    }
                    else{
                        ans+=num[i].c;
                        z++;
                    }
                }
                i--;
            }
        }
        else if(max(max(x,y),z)==y){
            sort(num+1,num+n+1,cmpb);
            i=n;
            while(y>n/2){
                if(num[i].fir=='b'){
                    y--;
                    num[i].fir=num[i].se;
                    ans-=num[i].a;
                    if(num[i].fir=='a'){
                        ans+=num[i].a;
                        x++;
                    }
                    else{
                        ans+=num[i].c;
                        z++;
                    }
                }
                i--;
            }
        }
        else{
            sort(num+1,num+n+1,cmpb);
            i=n;
            while(y>n/2){
                if(num[i].fir=='c'){
                    y--;
                    num[i].fir=num[i].se;
                    ans-=num[i].a;
                    if(num[i].fir=='a'){
                        ans+=num[i].a;
                        x++;
                    }
                    else{
                        ans+=num[i].b;
                        y++;
                    }
                }
                i--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
