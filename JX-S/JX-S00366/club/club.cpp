#include <bits/stdc++.h>
using namespace std;
int t,n,s = 0,aa,bb,cc;
struct rj{
    int a,b,c;
}sb[100086];
bool cmp(rj x,rj y){
    return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i = 1;i<=t;i++){
        cin>>n;
        s = 0;
        aa=0;
        bb=0;
        cc=0;
        for(int j = 1;j<=n;j++){
            cin>>sb[j].a>>sb[j].b>>sb[j].c;
        }
        sort(sb+1,sb+n+1,cmp);
        for(int k = 1;k<=n;k++){
            if(sb[k].a>=sb[k].b&&sb[k].a>=sb[k].c){
                if(aa<n/2&&max(abs(sb[k].a-sb[k].b),abs(sb[k].a-sb[k].c))>=max(abs(sb[k+1].a-sb[k+1].b),abs(sb[k+1].a-sb[k+1].c))){
                    s+=sb[k].a;
                    aa++;
                }
                else if(sb[k].b>sb[k].c&&bb<n/2&&abs(sb[k].b-sb[k].c)>=abs(sb[k+1].b-sb[k+1].c)){
                    s+=sb[k].b;
                    bb++;
                }
                else{
                    s+=sb[k].c;
                    cc++;
                }
            }
            else if(sb[k].b>=sb[k].a&&sb[k].b>=sb[k].c){
                if(bb<n/2&&max(abs(sb[k].b-sb[k].a),abs(sb[k].b-sb[k].c))>=max(abs(sb[k+1].b-sb[k+1].a),abs(sb[k+1].b-sb[k+1].c))){
                    s+=sb[k].b;
                    bb++;
                }
                else if(sb[k].a>sb[k].c&&bb<n/2&&abs(sb[k].a-sb[k].c)>=abs(sb[k+1].a-sb[k+1].c)){
                    s+=sb[k].a;
                    aa++;
                }
                else{
                    s+=sb[k].c;
                    cc++;
                }
            }
            else {
                if(cc<n/2&&max(abs(sb[k].c-sb[k].b),abs(sb[k].c-sb[k].a))>=max(abs(sb[k+1].c-sb[k+1].a),abs(sb[k+1].c-sb[k+1].a))){
                    s+=sb[k].c;
                    cc++;
                }
                else if(sb[k].b>sb[k].a&&bb<n/2&&abs(sb[k].b-sb[k].a)>=abs(sb[k+1].b-sb[k+1].a)){
                    s+=sb[k].b;
                    bb++;
                }
                else{
                    s+=sb[k].a;
                    aa++;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
