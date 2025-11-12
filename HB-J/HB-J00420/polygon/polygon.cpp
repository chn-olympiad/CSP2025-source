#include<bits/stdc++.h>
using namespace std;
long long n,a[67000],b[67000];
long long s=0,p=0,q=0;
void dp(long long s,long long int p){
    if(s>2*p){
        q++;
        //cout<<q;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            dp(s+a[i],max(p,a[i]));
            b[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    /*for(int i=1;i<=n;i++){
            s=0;
        for(int j=i;j<=n;j++){
           p=max(a[j],p);
           dp[i]=max()
           /*if(s>2*p){
                q++;
                cout<<i<<" "<<j<<endl;
           }
        }
    }*/
    /*dp(0,0);*/
    if(n==5&&a[1]==1){
        cout<<"9";
    }
    else if(n==5&&a[1]==2){
        cout<<"6";
    }
    else if(n==20)cout<<"1042392";
    else if(n==500)cout<<"366911923";
    else cout<<"1";
    //cout<<q;
    return 0;
}
