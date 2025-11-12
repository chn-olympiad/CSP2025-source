#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
long long read(){
    long long x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
void write(long long x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
long long fa[10010];
long long find(long long x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n=read(),m=read(),k=read();
    vector<pair<long long,pair<long long,long long>>> a(m);
    for(long long i=0;i<m;i++)a[i].S.F=read()-1,a[i].S.S=read()-1,a[i].F=read();
    sort(a.begin(),a.end());
    for(long long i=0;i<n;i++)fa[i]=i;
    vector<pair<long long,vector<pair<long long,pair<long long,long long>>>>> ANS;
    ANS.push_back({0,{}});
    for(auto i:a)
        if(find(i.S.F)!=find(i.S.S))
            fa[find(i.S.F)]=find(i.S.S),ANS[0].F+=i.F,ANS[0].S.push_back(i);
    long long ans=ANS[0].F;
    for(long long _=0;_<k;_++){
        long long w=read(),sz=ANS.size();
        vector<pair<long long,pair<long long,long long>>> A(n);
        for(long long i=0;i<n;i++)A[i].F=read(),A[i].S={i,n+_};
        sort(A.begin(),A.end());
        for(long long __=0;__<sz;__++){
            ANS.push_back({ANS[__].F+w,{}});
            for(long long i=0;i<=n+_;i++)fa[i]=i;
            for(long long i=0,j=0;i<ANS[__].S.size()||j<n;)
                if(j==n||(i<ANS[__].S.size()&&ANS[__].S[i].F<A[j].F)){
                    if(find(ANS[__].S[i].S.F)!=find(ANS[__].S[i].S.S))
                        fa[find(ANS[__].S[i].S.F)]=find(ANS[__].S[i].S.S),
                        ANS.back().S.push_back(ANS[__].S[i]);
                    else ANS.back().F-=ANS[__].S[i].F;
                    i++;
                }
                else{
                    if(find(A[j].S.F)!=find(A[j].S.S))
                        fa[find(A[j].S.F)]=find(A[j].S.S),ANS.back().F+=A[j].F,
                        ANS.back().S.push_back(A[j]);
                    j++;
                }
            ans=min(ans,ANS.back().F);
        }
    }
    write(ans);
    return 0;
}
