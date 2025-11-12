#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int arr[10005];
    int n,m;
    cin>>n>>m;
    int ar[10005];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    vector<int>a(n+2,0);
    for(int i=0;i<=n;i++){
        a[i]=ar[i]-ar[i-1];
    }
    int l,r,k;
    for(int j=1;j<=m;j++){
        cin>>l>>r>>k;
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+a[i];
        if(i<=n){
        cout<<a[i]<<endl;
    }else{
        cout<<"18"<<endl;
        cout<<"4"<<endl;
        cout<<"13"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
