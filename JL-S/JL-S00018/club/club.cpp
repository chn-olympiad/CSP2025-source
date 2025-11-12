#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct edge{
    int a;
    int b;
    int c;
    int m;
}p[100010];
int n;
bool w_a(edge a,edge b){
    int _a=max(a.b-a.a,a.c-a.a);
    int _b=max(b.b-b.a,b.c-b.a);
    return _a>_b;
}
bool w_b(edge a,edge b){
    int _a=max(a.a-a.b,a.c-a.b);
    int _b=max(b.a-b.b,b.c-b.b);
    return _a>_b;
}
bool w_c(edge a,edge b){
    int _a=max(a.b-a.c,a.a-a.c);
    int _b=max(b.b-b.c,b.a-b.c);
    return _a>_b;
}
void qwe(){
    int c_a=0,c_b=0,c_c=0;
    int m_a=0,m_b=0,m_c=0;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].b>>p[i].c;
        int x=min(min(p[i].a,p[i].b),p[i].c);
        p[i].a-=x;
        p[i].b-=x;
        p[i].c-=x;
        p[i].m=max(max(p[i].a,p[i].b),p[i].c);
        int y=max(max(p[i].a,p[i].b),p[i].c);
        ans+=x;
        if(p[i].a==y)
            m_a++;
        if(p[i].b==y)
            m_b++;
        if(p[i].c==y)
            m_c++;
    }
    //cout<<m_a<<' '<<m_b<<' '<<m_c<<endl;
    if(m_a<=n/2&&m_b<=n/2&&m_c<=n/2){
        for(int i=1;i<=n;i++){
            ans+=p[i].m;
        }
    }
    else if(m_a>n/2){
        sort(p+1,p+1+n,w_a);
        for(int i=1;i<=n;i++){
            if(p[i].m==p[i].a&&m_a>n/2){
                    ans+=max(p[i].b,p[i].c);
                    m_a--;
            }
            else
                ans+=p[i].m;
            //cout<<ans<<endl;
        }
    }
    else if(m_b>n/2){
        sort(p+1,p+1+n,w_b);
        for(int i=1;i<=n;i++){
            if(p[i].m==p[i].b&&m_b>n/2){
                    ans+=max(p[i].a,p[i].c);
                    m_b--;
            }
            else
                ans+=p[i].m;
        }
    }
    else{
        sort(p+1,p+1+n,w_c);
        for(int i=1;i<=n;i++){
            if(p[i].m==p[i].c&&m_c>n/2){
                    ans+=max(p[i].b,p[i].a);
                    m_c--;
            }
            else
                ans+=p[i].m;
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        qwe();
    }
    return 0;
}
