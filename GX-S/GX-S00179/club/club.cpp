#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct data{
    int a,b,c,mx,md,m,p;
}s[N];
int cnt[4];
int ans,n;
bool cmp(data x,data y){
    if(x.mx!=y.mx)return x.mx>y.mx;
    return x.md>y.md;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;cnt[1]=0;cnt[2]=0;cnt[3]=0;
        for(int i=0;i<=n+3;i++)s[i].a=s[i].b=s[i].c=0;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            s[i].mx = max(s[i].a,max(s[i].c,s[i].b));
            if(s[i].mx == s[i].a){
                s[i].md = max(s[i].b,s[i].c);
                s[i].mx -= s[i].md;
                if(s[i].md == s[i].b)s[i].p=2;
                else s[i].p=3;
                s[i].md -= min(s[i].b,s[i].c);
                s[i].m=1;
            }
            else if(s[i].mx == s[i].b){
                s[i].md = max(s[i].a,s[i].c);
                s[i].mx -= s[i].md;
                if(s[i].md == s[i].a)s[i].p=1;
                else s[i].p = 3;
                s[i].md -= min(s[i].a,s[i].c);
                s[i].m=2;
            }
            else{
                s[i].md = max(s[i].b,s[i].a);
                s[i].mx -= s[i].md;
                if(s[i].md == s[i].a)s[i].p=1;
                else s[i].p = 2;
                s[i].md -= min(s[i].b,s[i].a);
                s[i].m=3;
            }
        }
        sort(s+1,s+n+1,cmp);
        /*for(int i=1;i<=n;i++){
            cout<<s[i].a<<' '<<s[i].b<<' '<<s[i].c<<' '
                <<s[i].mx<<' '<<s[i].md<<' '<<s[i].m<<' '<<s[i].p<<endl;
        }*/
        for(int i=1;i<=n;i++){
            int tmp = max(s[i].a,max(s[i].b,s[i].c));
            if(cnt[s[i].m] < n/2){
                ans+=tmp;
                cnt[s[i].m]++;
            }
            else{
                cnt[s[i].p]++;
                if(s[i].p==1)ans+=s[i].a;
                else if(s[i].p==2)ans+=s[i].b;
                else ans+=s[i].c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
