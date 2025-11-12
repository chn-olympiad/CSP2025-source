#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N],b[N],c[N],maxx;
struct P{
    int a,b,c;
    bool operator<(const P&pp)const{
        return min(a,min(b,c))<min(min(pp.a,pp.b),pp.c);
    }
}v[N];
pair<int,int>pl[N];
void dfs(int sum,int stp,int as,int bs,int cs){
    if(stp==n){
        maxx=max(maxx,sum);
        return ;
    }
    if(as<n/2)dfs(sum+a[stp+1],stp+1,as+1,bs,cs);
    if(bs<n/2)dfs(sum+b[stp+1],stp+1,as,bs+1,cs);
    if(cs<n/2)dfs(sum+c[stp+1],stp+1,as,bs,cs+1);
    return ;
}
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        long long ans=0;
        int f=0,f2=0;
        for(int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0||c[i]!=0)f=1;
            if(c[i]!=0)f2=1;
            v[i].a=a[i];
            v[i].b=b[i];
            v[i].c=c[i];
            pl[i]=make_pair(a1-a2,a1);
        }
        if(f==0){
        sort(a+1,a+1+n);
        for(int i=n;i>n/2;i--)ans+=a[i];
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)a[i]=0;
        }else if(f2==0){
            sort(pl+1,pl+1+n);
            for(int i=1;i<=n/2;i++){
                ans+=pl[i].second-pl[i].first;
            }
            for(int i=n/2+1;i<=n;i++)ans+=pl[i].second;
            cout<<ans<<endl;
        }
        else if(n<=4) {
            dfs(0,0,0,0,0);
            cout<<maxx<<endl;
            maxx=0;
        }else{
            sort(v+1,v+1+n);
            int c1=0,c2=0,c3=0;
            for(int i=1;i<=n;i++){
                if(v[i].a=max(v[i].a,max(v[i].b,v[i].c))){
                    if(c1<n/2){
                        c1++;
                        ans+=v[i].a;
                    }
                    else if(v[i].b>v[i].c&&c2<n/2){
                        c2++;
                        ans+=v[i].b;
                    }else if(c3<n/2){
                        c3++;
                        ans+=v[i].c;
                    }
                }else if(v[i].b=max(v[i].a,max(v[i].b,v[i].c))){
                    if(c2<n/2){
                        c2++;
                        ans+=v[i].b;
                    }
                    else if(v[i].c>v[i].a&&c3<n/2){
                        c3++;
                        ans+=v[i].c;
                    }else if(c1<n/2){
                        c1++;
                        ans+=v[i].a;
                    }
                }else{
                    if(c3<n/2){
                        c3++;
                        ans+=v[i].c;
                    }
                    else if(v[i].a>v[i].b&&c1<n/2){
                        c1++;
                        ans+=v[i].a;
                    }else if(c2<n/2){
                        c2++;
                        ans+=v[i].b;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}