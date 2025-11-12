#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int num[10000];
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    bool b[10000]={0},b2[100000];
    int ans=0;
    int l,r;

    int m=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int ye=1;
            m=num[i];
            l=i;
            r=j;
            for(int x=i+1;x<=j;x++){
                if(b[x]==1) {
                    ye=0;
                    break;
                }
                m=m^num[x];
                b2[x]=1;

            }

            if(m==k and ye==1){
                ans++;
                for(int x=i;x<=j;x++){
                    b[x]=1;

                }
            }
        }
    }
    cout<<ans;
    return 0;
}
