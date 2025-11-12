#include <bits/stdc++.h>
using namespace std;

int t;
int n;
const int N=10e5+10;
int a1[N];
int a2[N];
int a3[N];
int f[N];
int r;
int ans;
int m1[N];
int m2[N];
int te2;
int te3;

int main(){
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n;
        r=n/2;
        for (int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            te2+=a2[i];
            te3+=a3[i];
        }
        if (n==2){
            int e[3];
            e[1]=max(a1[1],max(a2[1],a3[1]));

            e[2]=max(a1[2],max(a2[2],a3[2]));
            ans=e[1]+e[2];
            cout<<e[1]<<" "<<e[2]<<endl;
            cout<<ans<<endl;
            continue;
        }

        if (te2==0&&te3==0){
            sort(a1,a1+n+1);
            for (int i=n;i>n/2;i--){
                    //cout<<a1[i]<<" ";
                ans+=a1[i];
            }
            cout<<ans<<endl;
            ans=0;
            continue;
        }

        if (te3==0){
                int cnt=0;
                int s=0;
                int lnt=0;
                int o=0;
                for (int i=1;i<=n;i++){
                    if (a1[i]>a2[i]){
                        f[i]=1;
                        m1[s+1]=a1[i];
                        cnt++;
                    }
                    else {
                        f[i]=2;
                        m2[o+1]=a2[i];
                        lnt++;
                    }
                }
                sort (m1,m1+cnt+1);
                sort (m2,m2+cnt+1);
                for (int i=n;i>r;i--){
                    ans+=m1[i];
                    ans+=m2[i];
                }
                cout<<ans<<endl;
                return 0;
        }


    }
    return 0;
}
