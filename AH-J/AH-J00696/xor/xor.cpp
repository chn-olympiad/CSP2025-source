#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans,cnt;
int a[500005];
bool f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f=0;
        for(int j=1;j<=n;j++){
            ans=0;
            for(int x=i;x<=j;x++){
                ans=(ans^a[x]);
                if(ans==k){
                    cnt++;
                    i=x;
                    j=i;
                    f=1;
                    break;
                }
            }
            if(f==1){
                break;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
