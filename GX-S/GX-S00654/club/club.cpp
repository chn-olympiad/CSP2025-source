#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
template <class T>
void read(T& a){
    a=0;char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();
    while(ch>='0' && ch<='9'){
        a=(a<<1)+(a<<3)+ch-'0';
        ch=getchar();
    }
}
struct person{
    int a,b,c;
    bool operator < (const person& y){
        return b-a<y.b-y.a;
    }
};

int main(){
    #ifndef Db
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    #endif
    int T;
    read(T);
    while(T--){
        read(n);
        vector<person>p(n);
        bool c0=true;
        for(int i=0;i<n;++i){
            auto& x=p[i];
            read(x.a),read(x.b),read(x.c);
            if(x.c!=0) c0=false;
        }
        if(c0){
            sort(p.begin(),p.end());
            int sum =0;
            for(int i=0;i<n/2;++i) sum+=p[i].a;
            for(int i=n/2;i<n;++i) sum+=p[i].b;
            cout<<sum<<endl;
            return 0;
        }else for(int i=0;i<n;++i){

        }
    }
    return 0;
}
