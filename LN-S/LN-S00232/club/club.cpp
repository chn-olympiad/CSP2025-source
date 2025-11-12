#include<bits/stdc++.h>
using namespace std;
int tt;
int n;
int f[100050],s[100050],t[100050];
struct Node{
    int fi,se,th;
}m[100050];
int one[100050],two[100050],thr[100050];
int a,b,c;
void print1(){
    int ans=0;
    for(int i=1;i<=a;i++) ans+=f[one[i]];
    for(int i=1;i<=b;i++) ans+=s[two[i]];
    for(int i=1;i<=c;i++) ans+=t[thr[i]];
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>tt;
    while(tt--){
        cin>>n;
        int ma=n/2;
        for(int i=1;i<=n;i++){
            cin>>f[i]>>s[i]>>t[i];
            int mv=max(f[i],max(s[i],t[i]));
            int iv=min(f[i],min(s[i],t[i]));
            if(mv==f[i]){
                m[i].fi=1;
                if(iv==s[i]) m[i].th=2,m[i].se=3;
                else m[i].th=3,m[i].se=2;
            }
            else if(mv==s[i]){
                m[i].fi=2;
                if(iv==f[i]) m[i].th=1,m[i].se=3;
                else m[i].th=3,m[i].se=1;
            }
            else{
                m[i].fi=3;
                if(iv==s[i]) m[i].th=2,m[i].se=1;
                else m[i].th=1,m[i].se=2;
            }
        }
        for(int i=1;i<=n;i++){
            if(m[i].fi==1) one[++a]=i;
            else if(m[i].fi==2) two[++b]=i;
            else thr[++c]=i;
        }
        print1();
    }
    return 0;
}
