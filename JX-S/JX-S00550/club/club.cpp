#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int foumax(int a[],int n){
    int max=0,fla;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max);{
        max=a[i];
        fla=i;
        }
    }
    return fla;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,ans[t+1];
    memset(ans,0,sizeof(ans));
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n;
        k=n/2;
        int a[n][3],f1=0;
        for(int j=0;j<n;j++){
            cin>>a[j][0]>>a[j][1]>>a[j][2];
            if(a[j][1]!=0||a[j][2]!=0) f1=1;
            if(f1==1)
                ans[i]+=max(max(a[j][0],a[j][1]),a[j][2]);
        }
        if(f1==0){
            int x[n];
            for(int i=0;i<n;i++) x[i]=a[i][0];
            while(n>k){
                int fla=foumax(x,n);
                ans[i]+=x[fla];
                x[fla]=0;
                n--;
            }
        }
    }
    for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
    return 0;
}
