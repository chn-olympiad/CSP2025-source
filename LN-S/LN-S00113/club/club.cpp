#include<bits/stdc++.h>
using namespace std;
pair<long long ,long long> tb[100010][3];
pair<long long ,long long> ac[100010];
long long ak[5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;cin>>t;
    while(t--){
        long long n;cin>>n;
        for(int i=1;i<=n;++i){
            long long a,b,c; cin>>a>>b>>c;
            if(a>=b && a>=c){
                if(b>=c){
                    ac[i].first=a;
                    ac[i].second=i;
                    tb[i][1].first=a;
                    tb[i][1].second=1;
                    tb[i][2].first=b;
                    tb[i][2].second=2;
                    tb[i][3].first=c;
                    tb[i][3].second=3;
                }
                else if(b<c){
                    ac[i].first=a;
                    ac[i].second=i;
                    tb[i][1].first=a;
                    tb[i][1].second=1;
                    tb[i][2].first=c;
                    tb[i][2].second=3;
                    tb[i][3].first=b;
                    tb[i][3].second=2;
                }
            }
            else if(b>=c && b>=a){
                if(a>=c){
                    ac[i].first=b;
                    ac[i].second=i;
                    tb[i][1].first=b;
                    tb[i][1].second=2;
                    tb[i][2].first=a;
                    tb[i][2].second=1;
                    tb[i][3].first=c;
                    tb[i][3].second=3;
                }
                else if(c>a){
                    ac[i].first=b;
                    ac[i].second=i;
                    tb[i][1].first=b;
                    tb[i][1].second=2;
                    tb[i][2].first=c;
                    tb[i][2].second=3;
                    tb[i][3].first=a;
                    tb[i][3].second=1;
                }
            }
            else if(c>=a && c>=b){
                if(a>=b){
                    ac[i].first=c;
                    ac[i].second=i;
                    tb[i][1].first=c;
                    tb[i][1].second=3;
                    tb[i][2].first=a;
                    tb[i][2].second=1;
                    tb[i][3].first=b;
                    tb[i][3].second=2;
                }
                else if(a<b){
                    ac[i].first=c;
                    ac[i].second=i;
                    tb[i][1].first=c;
                    tb[i][1].second=3;
                    tb[i][2].first=b;
                    tb[i][2].second=2;
                    tb[i][3].first=a;
                    tb[i][3].second=1;
                }
            }
        }
        long long ans=0;
        sort(ac+1,ac+n+1);
        ak[1]=n/2;
        ak[2]=n/2;
        ak[3]=n/2;
        for(int i=n;i>=1;--i){
            for(int j=1;j<=3;++j){
                for(int k=1;k<=3;++k){
                    if(tb[ac[i].second][j].second==k && ak[k]!=0){
                        ans+=tb[ac[i].second][j].first;
                        ak[k]-=1;
                        break;

                    }
                }
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
