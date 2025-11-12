#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,all,pur,ans,ansx,ansy;
int a[1010];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    all=n*m;
    for(int i=1;i<=all;i++){
        cin>>a[i];
    }
    pur=a[1];
    sort(a+1,a+all+1,cmp);
    for(int i=1;i<=all;i++){
        if(a[i]==pur){
            ans=i;
            break;
        }
    }
    ansx=ans/n;
    if(ans%n!=0)ansx++;
    if(ansx%2==1){
        ansy=ans%n;
        if(ansy==0)ansy=m;
    }
    else{
        ansy=m-ans%n+1;
        if(ansy==m+1)ansy=1;
    }
    cout<<ansx<<" "<<ansy<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
