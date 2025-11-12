#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
const int N=5005;
int a[N],b[N];
int zui(){
    int an=0;
    for(int i=0;i<n;i++){
        if(b[i]){
            an=max(an,a[i]);
        }
    }
    return an;
}
bool k(){
    int sum=0;
    for(int i=0;i<n;i++){
        if(b[i]){
            sum+=a[i];
        }
    }
    if(sum>2*zui()){
        return true;
    }
    return false;
}
void zh(int m,int h){
    if(m==0){
        if(k()){
            ans++;
        }
        return;
    }
    for(int i=h+1;i+m<n;i++){
        b[i]=1;
        zh(m-1,i);
        b[i]=0;
    }
    if(k()){
        ans++;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[0]+a[1]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int m=2;i+m<n;m++){
            for(int j=0;j<n;j++){
                b[j]=0;
            }
            b[i]=1;
            zh(m,i);
            b[i]=0;
        }
    }
    cout<<ans;
    return 0;
}
