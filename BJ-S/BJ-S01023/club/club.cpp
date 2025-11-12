#include<bits/stdc++.h>
using namespace std;
long long t,n,a[3][100005],i[3],ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int b=1;b<=n;b++){
            long long maxn=-1,maxid,maxn2=-1;
            for(int c=0;c<3;c++){
                long long x;
                cin>>x;
                if(x>maxn){
                    maxn2=maxn;
                    maxn=x;
                    maxid=c;
                }else if(x>maxn2)maxn2=x;
            }
            ans=ans+maxn;
            a[maxid][++i[maxid]]=maxn-maxn2;
        }
        for(int b=0;b<3;b++){
            if(i[b]>n/2){
                sort(a[b]+1,a[b]+1+i[b]);
                for(int c=1;c<=i[b]-n/2;c++)ans=ans-a[b][c];
            }
            i[b]=0;
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}