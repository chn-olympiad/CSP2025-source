#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main (){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string aa;
    cin >> n>> m;
    cin >> aa;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==n){
        int flag=0;
        for(int i=0;i<aa.size();i++){
            if(aa[i]=='0'){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout << 0;
            return 0;
        }
        if(flag==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    flag==1;
                }
            }
            if(flag==1){
                cout << 0;
                return 0;
            }
            if(flag==0){
                long long ans=1;
                for(int i=n;i>=1;i--){
                      //  cout << "d";
                    ans=(ans*i)%998244353;
                }
                cout << ans;
                return 0;
            }
        }
    }else{
        cout << 0;
    }

    return 0;
}
