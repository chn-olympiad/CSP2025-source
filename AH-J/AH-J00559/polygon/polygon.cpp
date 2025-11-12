#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m;
    cin>>n;
    int a[10010];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                m=max(a[i],max(a[j],a[k]));
                if(m<(a[i]+a[j]+a[k]))cnt++;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
