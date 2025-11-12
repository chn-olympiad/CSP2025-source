#include<bits/stdc++.h>
using namespace std;
struct pers{
    int a,b,c;
};
bool structcmp(pers& a,pers& b){
    return (a.a)>(b.a);
}bool structcmpb(pers& a,pers& b){
    return (a.b)>(b.b);
}bool structcmpc(pers& a,pers& b){
    return (a.c)>(b.c);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        pers pres[n];
        for(int i=0;i<n;i++){
            cin>>pres[i].a>>pres[i].b>>pres[i].c;
        }
        sort(pres+0,pres+n,structcmp);
        /*for(int i=0;i<n;i++){
            cout<<pres[i].a<<' '<<pres[i].b<<' '<<pres[i].c<<endl;
        }*/

        int get=n/2,cnt=0;
        for(int i=0;i<get;i++){
            cnt+=pres[i].a;
            pres[i].a=-255;
        } 
        sort(pres+0,pres+n,structcmpb);
        int getl=get;
        for(int i=0;i<getl;i++){
            if(pres[i].a==-255){
                getl++;continue;}

            cnt+=pres[i].b;
            pres[i].b=-255;
        }
        sort(pres+0,pres+n,structcmpc);
        int getk=get;
        for(int i=0;i<getk;i++){
            if(pres[i]b==-255||pres[i]b==-255){
                getk++;continue;
            }
            cnt+=pres[i].c;
            pres[i].c=-255;
        }
    }
    cout<<cnt<<endl;
}
