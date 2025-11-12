#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int b[100005];
int c[100005];
bool cmp(int x,int y){return b[x]>b[y];}
int f(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        b[i]=abs(a[i][0]-a[i][1]);
        c[i]=i;
    }
    sort(c+1,c+1+n,cmp);
    int x=0,y=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[c[i]][0]>a[c[i]][1]&&x<n/2){
            x++;
            ans+=a[c[i]][0];
        }
        if(a[c[i]][0]<a[c[i]][1]&&y<n/2){
            y++;
            ans+=a[c[i]][1];
        }
        if(x==n/2){
            y++;
            ans+=a[c[i]][1];
        }
        if(y==n/2){
            x++;
            ans+=a[c[i]][0];
        }
    }
    cout<<ans<<"\n";
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
    f();
}
}
