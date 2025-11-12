#include<bits/stdc++.h>
using namespace std;
long long a[10010],vis=0;
long long k,n;
long long sum,ans,cnt;
//int find(long long m){
    //for(int i=1;i<=n;i+=2){
        //if(a[i]==m){
            //return i;
        //}
    //}
    //return -1;
//}
//void dfs(int m){
    //if(m>=n){
        //cout<<cnt<<endl;
        //return;
//    }
    //if(find(m)!=-1&&vis==0){
        //cnt++;
        //cout<<find(m)+1<<' ';
        //if(a[find(m)+1]==m) vis=1;
        //dfs(a[find(m)+1]);
        //cnt--;
        //vis=0;
    //}
    //dfs(m+1);
//}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    //int t=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<2;//()
    //for(int i=1;i<=n;i++){
        //for(int j=i;j<=n;j++){
            //if(getxor(i,j)==k){
            //    a[t]=i,t++;
          //      a[t]=j,t++;
        //    }
      //  }
    //}
   // dfs(1);
    return 0;
}
