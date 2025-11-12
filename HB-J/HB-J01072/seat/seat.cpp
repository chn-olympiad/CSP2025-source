#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1010]={};
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }int x=a[1],l;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x)l=i;
    }//cout<<l<<endl;
    if(l==n*m){
        cout<<m<<" "<<1;
        return 0;
    }
    cout<<(l+n-1)/n<<" ";
    if((l+n-1)%2==1){
        if(l%n==0)cout<<n;
        else cout<<l%n;
    }else{
        if((n-l%n+1)>n)cout<<(n-l%n+1)%n;
        else cout<<n-l%n+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
