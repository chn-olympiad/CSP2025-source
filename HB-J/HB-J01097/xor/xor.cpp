#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
const int N=5*1e5+5;
int n,k,ans,cnt;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            a[i]=-1;
            ans++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==-1)continue;
        cnt=a[i];
        for(int j=i+1;j<=n;j++){
            if(a[j]==-1)break;
            cnt^=a[j];
            if(cnt==k){
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}