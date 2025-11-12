#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N],ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j-i<2){
                continue;
            }
            int maxn=0,sum=0;
            for(int k=i;k<=j;k++){
                maxn=max(maxn,a[k]*2);
                sum+=a[k];
            }
            if(sum>maxn){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
