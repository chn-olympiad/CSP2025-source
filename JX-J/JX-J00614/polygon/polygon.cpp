#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
int dp[5005][5005];
int a[5005];
int b[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+a[i-1];
    }
    if(n==3&&a[1]+a[2]>a[3]){
        cout<<1<<'\n';
        return 0;
    }
    else if(n==3&&a[1]+a[2]<=a[3]){
        cout<<0<<'\n';
        return 0;
    }
    sort(a+1,a+n+1);
    //int i=1,j=3;
    ////int sum=a[1]+a[2]+a[3];
    //while(){
    //    j=i+2;
    //    int sum=a[i]+a[i+1];
    //    if(sum<)
    //}

    //for(int w=3;w<=n;w++){
      //  int i=2,j=w;
        //while(j<=n){
          //  if(b[i]-b[i-w]>a[j]){
            //    cnt++;
              //  cnt%=998244353;
            //}
            //
            //i++,j++;
        //}
    //}

//    for(int i1=1;i1<=n;i1++){
  //      for(int i2=i1;i2<=n;i2++){
    //        for(int i3=i2;i3<=n;i3++){
      //          for(int i4=i3;i4<=n;i4++){
        //            for(int i5=i4;i5<=n;i5++){
          //
            //        }
              //  }
            //}
        //}
    //}
    cout<<cnt;
    return 0;
}
