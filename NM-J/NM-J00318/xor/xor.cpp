#include <bits/stdc++.h>

using namespace std;
const int N=500010;
int a[N],s[N],n,k,ans=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=(s[i-1]^a[i]);
    }
    int lastr=0;
    for(int r=1;r<=n;r++){
        for(int l=lastr+1;l<=r;l++){
            if((s[r]^s[l-1])==k){
                ans++;
                lastr=r;
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
