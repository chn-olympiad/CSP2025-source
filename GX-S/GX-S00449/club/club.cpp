#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX=100050;
const int inf=0x3f3f3f3f;
int t,n,ans;
struct note{
    int a,b,c;
}p[MAX];
bool cmp(note a,note b){
    int p[3]={a.a,a.b,a.c},q[3]={b.a,b.b,b.c};
    sort(p,p+3);
    sort(q,q+3);
    if(p[2]!=q[2]){
        return p[2]>q[2];
    }
    if(p[1]!=q[1]){
        return p[1]>q[1];
    }
    if(p[0]!=q[0]){
        return p[0]>q[0];
    }
    return 1;
}
int Max(int a,int b,int c){
    return max(max(a,b),c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
        }
        sort(p+1,p+1+n,cmp);
        int n1=0,n2=0,n3=0;
        for(int i=1;i<=n;i++){
            int k[3]={p[i].a,p[i].b,p[i].c};
            sort(k,k+3);
            if(k[2]==p[i].a&&n1<n/2)n1++,ans+=k[2];
            else if(k[2]==p[i].b&&n2<n/2)n2++,ans+=k[2];
            else if(k[2]==p[i].c&&n3<n/2)n3++,ans+=k[2];
            else{
                if(k[1]==p[i].a&&n1<n/2)n1++,ans+=k[1];
                else if(k[1]==p[i].b&&n2<n/2)n2++,ans+=k[1];
                else if(k[1]==p[i].c&&n3<n/2)n3++,ans+=k[1];
                else{
                    if(n1<n/2)n1++,ans+=k[0];
                    else if(n2<n/2)n2++,ans+=k[0];
                    else if(n3<n/2)n3++,ans+=k[0];
                }
            }
        }
        cout<<ans<<endl;
    }
}
