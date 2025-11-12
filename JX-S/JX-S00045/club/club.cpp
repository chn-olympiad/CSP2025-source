#include<bits/stdc++.h>
using namespace std;
int n,a1[10005],a2[10005],a3[10005];
int ans1=0,ans2=0,ans3=0,c1=0,c2=0,c3=0;

bool f[10005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        for(int j=1;j<=t;j++){
            cin>>a1[j]>>a2[j]>>a3[j];

        }
        for(int k=1;k<=t;k++){
            if(a1[k]>a2[k]&&a1[k]>a3[k]&&c1<=(t/2)){
                ans1+=a1[k];
                c1++;
            }
            else if(a2[k]>a1[k]&&a2[k]>a3[k]&&c2<=(t/2)){
                ans2+=a2[k];
                c2++;
            }
            else if(a3[k]>a2[k]&&a3[k]>a1[k]&&c3<=(t/2)){
                ans3+=a3[k];
                c3++;
            }
        }
        c1=c2=c3=0;
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    return 0;
}

