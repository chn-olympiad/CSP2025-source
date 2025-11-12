#include<bits/stdc++.h>
using namespace std;
const unsigned int mod=998244353;
int n,k;//what's the purpose of education?
int a[500005];
int f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
 //   cout<<k<<endl;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]^a[i];
        if(a[i]!=1)flag=1;
    }
    if(k<=1){
        if(k==0&&!flag){
            cout<<(n>>1);
            return 0;
        }
        else{
            int cnt=0,m=a[1];
            for(int i=1,j=2;i<n,j<=n;){
                while(m!=k){
                    m^=a[j];
                    j++;
                }
                cnt++;
                m=a[j];
                i=j;
                j++;
            }
            cout<<cnt;
            return 0;
        }
    }
    int cnt=0;
    for(int i=1,j=0;i<=n,j<=n;i++){
        while(f[j]^f[i]!=k&&j<=n){
            j++;
        }
        if(f[j]^f[i]==k){
            cnt++;
          //  cout<<i<<' '<<j<<endl;
            i=j;
            j++;
        }
    }
    cout<<cnt;
    return 0;
    /*
    for(int i=1;i<=n;i++){
        int m=0;
        for(int j=i;j<=n;j++){
            m^=a[j];
            cout<<i<<" "<<j<<": "<<m<<endl;
        }//i want to go back home QAQ
    }*/
}
