#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int maxx(int a,int b,int c,int d){
    int maxn=-1;
    if(a>maxn) maxn=a;
    if(b>maxn) maxn=b;
    if(c>maxn) maxn=c;
    if(d>maxn) maxn=d;
    return maxn;
}
void four(){
    int sumn=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int f=0;f<n;f++){
                if(a[i]!=a[j]&&a[i]!=a[f]){
                    int maxn=-1,sum=0;
                    maxn=maxx(a[i],a[j],a[f],-2);
                    sum=a[i]+a[j]+a[f];
                    if(maxn*2<sum) sumn++;
                }
            }
        }
    }
    int maxn2=-1,sum2=0;
    maxn2=maxx(a[0],a[1],a[2],a[3]);
    sum2=a[0]+a[1]+a[2]+a[3];
    if(maxn2*2<sum2) sumn++;
    cout<<sumn;
}
int te(){
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        int maxn=-1,sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(a[i]>maxn) maxn=a[i];
        }
        if(maxn*2>=sum){
            cout<<0;
            return 0;
        }else{
            cout<<1;
            return 0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(te()==0) return 0;
    if(n==4) four();
    return 0;
}
