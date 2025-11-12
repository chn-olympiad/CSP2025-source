#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int suma=0,sumb=0,sumc=0;
struct s{
    int a,b,c;
};
s N[100005]={},ins;
vector<s> t[4]={};
int maxx(){
    if(ins.a>=ins.b&&ins.a>=ins.c){
        suma++;
        t[1].push_back(ins);
        return ins.a;
    }
    if(ins.b>=ins.c){
        sumb++;
        t[2].push_back(ins);
        return ins.b;
    }
    sumc++;
    t[3].push_back(ins);
    return ins.c;
}
int maxx2(s m){
    return max(max(m.a,m.b),m.c);
}
int midd(s m){
    return m.a+m.b+m.c-max(max(m.a,m.b),m.c)-min(min(m.a,m.b),m.c);
}
int maxsum(){
    if(suma>=sumb&&suma>=sumc)return 1;
    if(sumb>=sumc)return 2;
    return 3;
}
bool cmp(s x,s y){
    return (maxx2(x)-midd(x))<(maxx2(y)-midd(y));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n,ans=0;
    cin>>T;
    for(int tt=0;tt<T;tt++){
        cin>>n;
        ans=suma=sumb=sumc=0;
        for(int i=0;i<n;i++){
            cin>>ins.a>>ins.b>>ins.c;
            ans+=maxx();
        }
        //cout<<ans<<endl;
        if(max(max(suma,sumb),sumc)>(n/2)){
            sort(t[maxsum()].begin(),t[maxsum()].end(),cmp);
            //cout<<suma<<" "<<sumb<<" "<<sumc<<" ";
            //cout<<(max(max(suma,sumb),sumc)-(n/2))<<endl;
            for(int i=0;i<max(max(suma,sumb),sumc)-(n/2);i++){
                ans-=maxx2(t[maxsum()][i])-midd(t[maxsum()][i]);
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<4;i++)t[i].clear();
    }
    return 0;
}
