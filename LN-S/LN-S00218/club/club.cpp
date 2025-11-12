#include <bits/stdc++.h>
using namespace std;
struct node{
int a,b,c,maxn;
}s[100005];
struct ccff{
int id,mi,mid;
}aa[100005];
int cmp(ccff a,ccff b){
return a.mi>b.mi;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            s[i].maxn=max(s[i].a,max(s[i].b,s[i].c));
            if(s[i].maxn==s[i].a) aa[i].mid=1;
            else if(s[i].maxn==s[i].b) aa[i].mid=2;
            else aa[i].mid=3;
            if(s[i].a>=s[i].b and s[i].b>=s[i].c){
                aa[i].mi=s[i].maxn-s[i].b;
            }
            else if(s[i].a>=s[i].c and s[i].c>=s[i].b){
                aa[i].mi=s[i].maxn-s[i].c;
            }
            else if(s[i].b>=s[i].a and s[i].a>=s[i].c){
                aa[i].mi=s[i].maxn-s[i].a;
            }
            else if(s[i].b>=s[i].c and s[i].c>=s[i].a){
                aa[i].mi=s[i].maxn-s[i].c;
            }
            else if(s[i].c>=s[i].a and s[i].a>=s[i].b){
                aa[i].mi=s[i].maxn-s[i].a;
            }
            else if(s[i].c>=s[i].b and s[i].b>=s[i].a){
                aa[i].mi=s[i].maxn-s[i].b;
            }
            aa[i].id=i;
        }
        sort(aa+1,aa+1+n,cmp);
        int ca=0,cb=0,cc=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(aa[i].mid==1 and (ca+1)<=(n/2)){
                ans+=s[aa[i].id].maxn;
                ca++;
            }
            else if(aa[i].mid==2 and (cb+1)<=(n/2)){
                ans+=s[aa[i].id].maxn;
                cb++;
            }
            else if(aa[i].mid==3 and (cc+1)<=(n/2)){
                ans+=s[aa[i].id].maxn;
                cc++;
            }
            else if(aa[i].mid==1 and (ca+1)>(n/2)){
                if(s[aa[i].id].b>=s[aa[i].id].c){
                    ans+=s[aa[i].id].b;
                    cb++;
                }
                else{
                    ans+=s[aa[i].id].c;
                    cc++;
                }
            }
            else if(aa[i].mid==2 and (cb+1)>(n/2)){
                if(s[aa[i].id].a>=s[aa[i].id].c){
                    ans+=s[aa[i].id].a;
                    ca++;
                }
                else{
                    ans+=s[aa[i].id].c;
                    cc++;
                }
            }
            else if(aa[i].mid==3 and (cc+1)>(n/2)){
                if(s[aa[i].id].b>=s[aa[i].id].a){
                    ans+=s[aa[i].id].b;
                    cb++;
                }
                else{
                    ans+=s[aa[i].id].a;
                    ca++;
                }
            }

        }
        cout<<ans<<endl;
    }

    return 0;
}
