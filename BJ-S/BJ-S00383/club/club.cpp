#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n;
struct STUDENT{
    int a,b,c;
} s[N];
struct SEARCH{
    int c1=0,c2=0,c3=0;
    int val=0;
    int index;
};
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
    }
    stack<SEARCH> st;
    st.push(SEARCH{0,0,0,0,1});
    int ans=0;
    while(!st.empty()){
        SEARCH ip=st.top();
        st.pop();
        if(ip.index==n+1){
            ans=max(ip.val,ans);
            continue;
        }
        if(ip.c1<n/2)
            st.push(SEARCH{ip.c1+1,ip.c2,ip.c3,ip.val+s[ip.index].a,ip.index+1});
        if(ip.c2<n/2)
            st.push(SEARCH{ip.c1,ip.c2+1,ip.c3,ip.val+s[ip.index].b,ip.index+1});
        if(ip.c3<n/2)
            st.push(SEARCH{ip.c1,ip.c2,ip.c3+1,ip.val+s[ip.index].c,ip.index+1});
    }
    printf("%d\n",ans);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
