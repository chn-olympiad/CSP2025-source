#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long t[N],ans,n,q,ll,rr,d,l2,r2;
bool w;
string c1,c2;
struct node{
    long long l,r,l1,r1;
}s[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int j=1;j<=n;j++){
        cin>>c1>>c2;
        w=0;
        d=c1.size();
        for(int i=0;i<d;i++){
            if(c1[i]=='a'&&w==0){
                s[j].l++;
            }
            else if(c1[i]=='b') w=1;
            else{
                s[j].r++;
            }
        }
        w=0;
        d=c2.size();
        for(int i=0;i<d;i++){
            if(c2[i]=='a'&&w==0){
                s[j].l1++;
            }
            else if(c2[i]=='b') w=1;
            else{
                s[j].r1++;
            }
        }
    }
    for(int j=1;j<=q;j++){
        ans=0;
        cin>>c1>>c2;
        w=0;
        d=c1.size();
        for(int i=0;i<d;i++){
            if(c1[i]=='a'&&w==0){
                ll++;
            }
            else if(c1[i]=='b') w=1;
            else{
                rr++;
            }
        }
        w=0;
        d=c2.size();
        for(int i=0;i<d;i++){
            if(c2[i]=='a'&&w==0){
                l2++;
            }
            else if(c2[i]=='b') w=1;
            else{
                r2++;
            }
        }
        for(int i=1;i<=n;i++){
            if((s[i].l<=ll)&&(s[i].r<=rr)&&(s[i].l!=s[i].l1)&&(s[i].l1<=l2)&&(s[i].r1<=r2)&&(abs(rr-r2)<=abs(s[i].r-s[i].r1))){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}