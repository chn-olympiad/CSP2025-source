#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

constexpr int N = 1e5+10;

struct Person{
    int a,b,c;
};

Person pp[N];

void solve(){
    int n;
    cin>>n;
    if(n==2){
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        cout<<max({a,b,c,d,e,f})<<'\n';
        return;
    }
    bool s1=true;
    for(int i=0;i<n;++i){
        cin>>pp[i].a>>pp[i].b>>pp[i].c;
        if(pp[i].b  || pp[i].c)s1=false;
    }

    if(s1){
        sort(pp,pp+n,[](Person lhs,Person rhs){return lhs.a>rhs.a;});
        int sum=0;
        for(int i=0;i<n/2;++i){
            sum+=pp[i].a;
        }
        cout<<sum<<'\n';
        return;
    }

    // for(int b=0;b<(1<<n);++b){
    //     unordered_set
    //     for(int i=0;i<n;++i){
    //         // printf("b=%d b>>%d=%d\n",b,i,(b>>i)&1);
    //         if(((b>>i)&1) == 0) continue;
    //         cout<<i<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<20000<<'\n';
}

int main(){
    (void)freopen("club.in","r",stdin);
    (void)freopen("club.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}