#include<bits/stdc++.h>
using namespace std;

struct P{
    int a,b,c;
} like[100005];;
int n;

int cou[4]={0};
int func(int w,int sor){
    if(w>n)
        return sor;

    int b=0;
    for(int i=1;i<=3;++i){
        if(cou[i]<(n/2)){
            ++cou[i];
            if(i==1)
                b=max(b,func(w+1,sor+like[w].a));
            else if(i==2)
                b=max(b,func(w+1,sor+like[w].b));
            else if(i==3)
                b=max(b,func(w+1,sor+like[w].c));
            --cou[i];
        }
    }

    return b;
}

int func_b(int w,int sor){
    if(w>n)
        return sor;

    int b=-1;
    for(int i=1;i<=2;++i){
        if(cou[i]<(n/2)){
            ++cou[i];
            if(i==1)
                b=max(b,func_b(w+1,sor+like[w].a));
            else if(i==2)
                b=max(b,func_b(w+1,sor+like[w].b));
            --cou[i];
        }
    }

    return b;
}

bool sr(P u,P v){
    return u.a>v.a;
}
int func_a(){
    sort(like+1,like+n+1,sr);
    int b=0;
    for(int i=1;i<=n/2;++i){
        b+=like[i].a;
    }
    return b;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){

    cin>>n;
    bool b=false,c=false;
    for(int i=1;i<=n;++i){
        cin>>like[i].a>>like[i].b>>like[i].c;
        b|=(bool)like[i].b;
        c|=(bool)like[i].c;
    }

    if((!b)&&(!c))
        cout<<func_a()<<endl;
    else if((!c)&&b)
        cout<<func_b(1,0)<<endl;
    else
        cout<<func(1,0)<<endl;

}
    return 0;
}
