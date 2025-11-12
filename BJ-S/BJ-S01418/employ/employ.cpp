#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    int qy=998244353;
    long long ans=1;
    cin>>n>>m;
    string a;
    cin>>a;
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    int sl=0;
    for(int i=0;i<a.length();i++){
        if(i==1) break;
        sl++;
    }
    if(m==1&&sl>0){
        int rs=0;
        for(int i=0;i<n;i++){
            if(c[i]<=sl) rs++;
        }
        for(int i=2;i<=n-rs;i++){
            ans*=i;
            ans%=qy;
        }
        for(int i=rs;i<=n-sl;i++){
            ans*=i;
            ans%=qy;
        }
        cout<<ans;
    }else{
        for(int i=2;i<=n;i++){
            ans*=i;
            ans%=qy;
        }
        cout<<ans;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
