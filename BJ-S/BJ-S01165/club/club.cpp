#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=101000;
#define int long long
struct stu{
    int a,b,p;
}s[maxn];
int T,n,x,y,z,tot1,tot2,tot3,maxx,delta,ans;
bool operator<(stu xx,stu yy){
    return (xx.p==maxx^yy.p==maxx)?bool(xx.p==maxx):bool(xx.a-xx.b<yy.a-yy.b);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        ans=tot1=tot2=tot3=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            if(x>=max(y,z))s[i]={x,max(y,z),1},tot1++;
            else if(y>=max(x,z))s[i]={y,max(x,z),2},tot2++;
            else s[i]={z,max(x,y),3},tot3++;
            ans+=s[i].a;
        }
        if(tot1>n/2)maxx=1,delta=tot1-n/2;
        else if(tot2>n/2)maxx=2,delta=tot2-n/2;
        else if(tot3>n/2)maxx=3,delta=tot3-n/2;
        else{
            cout<<ans<<"\n";
            continue;
        }
        sort(s+1,s+n+1);
        for(int i=1;i<=delta;i++)ans-=s[i].a-s[i].b;
        cout<<ans<<"\n";
    }
    return 0;
}