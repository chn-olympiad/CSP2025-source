#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
    int maxx;
    int ma2x;
    int fs;
};
node pl[120000];
node a1[120000],b1[120000],c1[120000];
bool cmp(node x,node y){
    return x.fs>y.fs;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        /////////////////////////////
        for(int i=1;i<=n;i++){
            cin >> pl[i].a >> pl[i].b >> pl[i].c;
            if(pl[i].a==max({pl[i].a,pl[i].b,pl[i].c})){
               pl[i].maxx=1;
            }else if(pl[i].b==max(pl[i].b,pl[i].c)){
                pl[i].maxx=2;
            }else{
                pl[i].maxx=3;
            }
        if(pl[i].maxx==1){
            if(pl[i].b>pl[i].c){
                pl[i].ma2x=2;
                pl[i].fs=pl[i].a-pl[i].b;
            }else{
                pl[i].ma2x=3;
                pl[i].fs=pl[i].a-pl[i].c;
            }
        }else if(pl[i].maxx==2){
            if(pl[i].a>pl[i].c){
                pl[i].ma2x=1;
                pl[i].fs=pl[i].b-pl[i].a;
            }else{
                pl[i].ma2x=3;
                pl[i].fs=pl[i].b-pl[i].c;
            }
        }else if(pl[i].maxx==3){
            if(pl[i].a>pl[i].b){
                pl[i].ma2x=1;
                pl[i].fs=pl[i].c-pl[i].a;
            }else{
                pl[i].ma2x=2;
                pl[i].fs=pl[i].c-pl[i].b;
            }
        }
        }
        /////////////////////////
    int al=1,bl=1,cl=1;
    for(int i=1;i<=n;i++){
        if(pl[i].maxx==1){
            a1[al]=pl[i];
            al++;
        }else if(pl[i].maxx==2){
            b1[bl]=pl[i];
            bl++;
        }else{
            c1[cl]=pl[i];
            cl++;
        }
    }
        //////////////////////
        sort(a1+1,a1+al,cmp);
        sort(b1+1,b1+bl,cmp);
        sort(c1+1,c1+cl,cmp);
        ////////////////////
        long long ans=0;
        for(int i=1;i<al;i++)ans+=a1[i].a;
        for(int i=1;i<bl;i++)ans+=b1[i].b;
        for(int i=1;i<cl;i++)ans+=c1[i].c;
        /////////////////////////
        if((al-1)>(n/2)){
            for(int i=(n/2)+1;i<al;i++)ans-=a1[i].fs;
        }else if((bl-1)>(n/2)){
            for(int i=(n/2)+1;i<bl;i++)ans-=b1[i].fs;
        }else if((cl-1)>(n/2)){
            for(int i=(n/2)+1;i<cl;i++)ans-=c1[i].fs;
        }
        cout <<ans<< endl;
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
//priority_queue<int,vector<int>,greater<int>>p;
