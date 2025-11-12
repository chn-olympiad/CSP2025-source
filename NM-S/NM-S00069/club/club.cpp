#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,a[10001][4],sum=0,s[10001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n;
        sum=0;
        for(j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            sum+=max(max(a[j][1],a[j][2]),a[j][3]);

        }
        s[i]=sum;
    }
    for(int i=1;i<=t;i++){
        cout<<s[i]<<endl;
    }
    cout<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
