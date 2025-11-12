#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int cnt=3,ans=0;
int a[N];
int n,m,r,h,l;
bool cpp(int x,int y){
   return x>y;
}
int dfs(int now,int he,int maxn,int k,int last){

   if(now==cnt){
        if(maxn*2<he){
            ans++;
            ans=ans%998244353;

        }

      return 0;
   }

    for(int i=k;i<=n;i++){
      int maxn1=maxn,last1=last;

        maxn=max(maxn,a[i]);
        last=a[i];
        k+=1;
        dfs(now+1,he+a[i],maxn,k,last);
       maxn=maxn1;
       last=last1;

    }

}
int main(){
   freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(cnt<=n){
             dfs(0,0,0,1,0);
        cnt++;
    }
    cout<<ans;
   return 0;
}
/////////// i am sleepy
/////my brain is as smooth as koala now.
/////////i am silly now............
/////////i am missing my bed;
/////what can i do......
//////////no..........
////////what a loud hotel it is!!!!!!!
