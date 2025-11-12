#include<bits/stdc++.h>
//#define int long long
using namespace std;
int T,n,rs[3],ans;
struct myd{
    int a,b,c,sum;
}m[100005];
bool cmp(myd A,myd B){
    return A.sum>B.sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        rs[0]=0,rs[1]=0,rs[2]=0;
        for(int i=0;i<n;i++){
            cin>>m[i].a>>m[i].b>>m[i].c;
            m[i].sum=m[i].a+m[i].b+m[i].c;
        }
        sort(m,m+n,cmp);
        for(int i=0;i<n;i++){
            if(m[i].a>=m[i].b&&m[i].a>=m[i].c){
                if(rs[0]+1<=n/2){
                    ans+=m[i].a;
                    rs[0]++;
                }else if(m[i].c>=m[i].b){
                    ans+=m[i].c;
                    rs[2]++;
                }else{
                    ans+=m[i].b;
                    rs[1]++;
                }
            }else if(m[i].b>=m[i].a&&m[i].b>=m[i].c){
                if(rs[1]+1<=n/2){
                    ans+=m[i].b;
                    rs[1]++;
                }else if(m[i].a>=m[i].c){
                    ans+=m[i].a;
                    rs[0]++;
                }else{
                    ans+=m[i].c;
                    rs[2]++;
                }
            }else if(m[i].c>=m[i].b&&m[i].c>=m[i].a){
                if(rs[2]+1<=n/2){
                    ans+=m[i].c;
                    rs[2]++;
                }else if(m[i].a>=m[i].b){
                    ans+=m[i].a;
                    rs[0]++;
                }else{
                    ans+=m[i].b;
                    rs[1]++;
                }
            }
        }
        cout<<rs[0]<<" "<<rs[1]<<" "<<rs[2]<<" ";
        cout<<ans<<endl;
    }
    return 0;
}
