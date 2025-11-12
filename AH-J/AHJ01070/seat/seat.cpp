#include<bits/stdc++.h>
using namespace std;
/*

共有 n × m 名考生,其中所有考生成绩 互不相同
n × m 名考生将按照 成绩
1 ≤ n ≤ 10,1 ≤ m ≤ 10;
• 对于所有 1 ≤ i ≤ n × m,均有 1 ≤ a i ≤ 100,且 a 1 , a 2 , . . . , a n×m 互不相同。
*/
int n,m,ans;
int a[105];
int b[11][11];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    int k=a[1];
    sort(a+1,a+1+t,cmp);
  //for(int i=1;i<=t;i++){
  //    cout<<a[i]<<" ";
  //}
    for(int i=1;i<=t;i++){
        if(a[i]==k){
            ans=i;
           //out<<ans<<endl;
        }
    }
    int cnt =(int)((double)ans/(double)n+0.99);
    //ut<<cnt<<endl;
    if(cnt%2!=0){
        if(ans%n==0)    cout<<cnt<<" "<<n;
        else            cout<<cnt<<" "<<ans%n;
    }else{
        if(ans%n==0)    cout<<cnt<<" "<<"1";
        else            cout<<cnt<<" "<<n-(ans%n)+1;
    }
    return 0;

}

