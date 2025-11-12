#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a,b,c;
}s[100010];
bool cmp(node q,node h){
    if(q.a==h.a){
        if(q.b==h.b){
            return q.c>h.c;
        }
        return q.b>h.b;
    }
    return q.a>h.a;
}
long long n,m,k,t,xa,ya,za;
vector<long long> x,y,z;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        xa=ya=za=0;
        x.clear();
        y.clear();
        z.clear();
        cin>>n;
        for(long long i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;

        }
        sort(s+1,s+n+1,cmp);
        for(long long i=1;i<=n;i++){
            if(s[i].a>s[i].b&&s[i].a>s[i].c&&x.size()<n/2){
                x.push_back(s[i].a);
                xa+=s[i].a;
            }
            else if(s[i].b>s[i].c&&y.size()<n/2){
                y.push_back(s[i].b);
                ya+=s[i].b;
            }
            else if(z.size()<n/2){
                z.push_back(s[i].c);
                za+=s[i].c;
            }
        }
        cout<<xa+ya+za<<'\n';
    }
    return 0;
}
