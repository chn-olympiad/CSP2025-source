#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+2;
struct node{
    int a,b,c;
}s[N],num;
ll t,n,ans;
bool cmp(node l,node r){
    return (max(l.a,max(l.b,l.c))*2-l.a-l.b-l.c)>(max(r.a,max(r.b,r.c))*2-r.a-r.b-r.c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].b>>s[i].c;
        num.a=n/2,num.b=n/2,num.c=n/2;
        sort(s+1,s+n+1,cmp);
//        for(int i=1;i<=n;i++) cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<endl;
        for(int i=1;i<=n;i++){
            int maxn=max(s[i].a,max(s[i].b,s[i].c));
            if(maxn==s[i].a){
                num.a--;
                if(num.a<0){
                    maxn=max(s[i].b,s[i].c);
                    if(maxn==s[i].b){
                        num.b--;
                        if(num.b<0){
                            num.c--;
                            ans+=s[i].c;
                        }
                        else ans+=s[i].b;
                    }
                    if(maxn==s[i].c){
                        num.c--;
                        if(num.c<0){
                            num.b--;
                            ans+=s[i].b;
                        }
                        else ans+=s[i].c;
                    }
                }
                else ans+=s[i].a;
            }
            else if(maxn==s[i].b){
                num.b--;
                if(num.b<0){
                    maxn=max(s[i].a,s[i].c);
                    if(maxn==s[i].a){
                        num.a--;
                        if(num.a<0){
                            num.c--;
                            ans+=s[i].c;
                        }
                        else ans+=s[i].a;
                    }
                    if(maxn==s[i].c){
                        num.c--;
                        if(num.c<0){
                            num.a--;
                            ans+=s[i].a;
                        }
                        else ans+=s[i].c;
                    }
                }
                else ans+=s[i].b;
            }
            else{
                num.c--;
                if(num.c<0){
                    maxn=max(s[i].b,s[i].a);
                    if(maxn==s[i].b){
                        num.b--;
                        if(num.b<0){
                            num.a--;
                            ans+=s[i].a;
                        }
                        else ans+=s[i].b;
                    }
                    if(maxn==s[i].a){
                        num.a--;
                        if(num.a<0){
                            num.b--;
                            ans+=s[i].b;
                        }
                        else ans+=s[i].a;
                    }
                }
                else ans+=s[i].c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
// gan jue zi ji dai ma xiang tiao long