#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,;
    cin>>T;
    while(T--){
    int n,m=0,w=0,f=0,ans=0;
    cin>>n;
    int a[n+5],b[n+5],c[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
       if(a[i]<b[i]>c[i]){
       if(w>n/2){
       if(a[i]>c[i]){
       m++;
       ans+=a[i];
       }
       else {
       f++;
       ans+=c[i];
       }
       }
       else{
       w++;
       ans+=b[i];
       }
       }
       if(b[i]<a[i]>c[i]){
       if(m>n/2){
       if(b[i]>c[i]){
       w++;
       ans+=b[i];
       }
       else {
       f++;
       ans+=c[i];
       }
       }
       else{
       m++;
       ans+=a[i];
       }
       }
       if(a[i]<c[i]>b[i]){
       if(f>n/2){
       if(b[i]>a[i]){
       w++;
       ans+=b[i];
       }
       else {
       m++;
       ans+=a[i];
       }
       }
       else{
       f++;
       ans+=c[i];
       }
       }
    }
    cout<<ans<<endl;
    }
    return 0;
}
//赞美欧姆尼塞亚，赞美万机之神，机魂大悦 出A题100分
