#include<iostream>
using namespace std;
int n;
int a[510]={};
long long ans=0;
long long l[510]={};
long long sum1=0;
int main(){
    int n1=n;
    freopen("polygon,in","r",stdin);
    freopen("polygon.out","w",stdout);
    int mx=0,sum=0;
    cin>>n;
    if(n==3){
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx) mx=a[i];
        sum+=a[i];
    }
    int t=2*mx;
    if(sum>t) cout<<1;
    else cout<<0;
    }else{   //pianfen qiu cn1 dao cnn de he
        ans=n;
        l[1]=n;
        l[0]=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=2;i<=n;i++){
     long long t1;
     if(i<=n/2){
            ans=ans*(n-i+1)/i;
            l[i]=ans;
     }
     else ans=l[n-i];
     if(i>2) sum1+=ans;
 //    cout<<ans<<endl;
    }

    printf("%lld",sum1);
}
return 0;
}
