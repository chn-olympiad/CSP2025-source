#include <bits/stdc++.h>
using namespace std;
constexpr int N=100005;
int n;
int n1[N],n2[N],n3[N];
int c1,c2,c3;
int z1[N],z2[N],z3[N];
int s[N];
long long ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while (T--){
        ans=c1=c2=c3=0;
        cin>>n;
        for (int z=0;z<n;z++){
            cin>>n1[z]>>n2[z]>>n3[z];
            if (n1[z]>=n2[z] && n1[z]>=n3[z])z1[c1++]=z;
            else if (n2[z]>=n1[z] && n2[z]>=n3[z])z2[c2++]=z;
            else z3[c3++]=z;
        }
        for (int z=0;z<c1;z++){
            ans+=n1[z1[z]];
        }
        for (int z=0;z<c2;z++){
            ans+=n2[z2[z]];
        }
        for (int z=0;z<c3;z++){
            ans+=n3[z3[z]];
        }
        if (c1>n/2){
            for (int z=0;z<c1;z++){
                s[z]=n1[z1[z]]-max(n2[z1[z]],n3[z1[z]]);
            }
            sort(s,s+c1);
            for (int z=0;z<c1-n/2;z++){
                ans-=s[z];
            }
        }else if (c2>n/2){
            for (int z=0;z<c2;z++){
                s[z]=n2[z2[z]]-max(n1[z2[z]],n3[z2[z]]);
            }
            sort(s,s+c2);
            for (int z=0;z<c2-n/2;z++){
                ans-=s[z];
            }
        }else if (c3>n/2){
            for (int z=0;z<c3;z++){
                s[z]=n3[z3[z]]-max(n1[z3[z]],n2[z3[z]]);
            }
            sort(s,s+c3);
            for (int z=0;z<c3-n/2;z++){
                ans-=s[z];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
