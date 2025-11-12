#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],s,r,cnt;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    //hui lai ce RP++
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   cin>>n>>m;
   s=n*m;
   for(int i=1;i<=s;i++){
    cin>>a[i];
   }
   r=a[1];
   sort(a+1,a+1+s,cmp);
   //for(int i=1;i<=s;i++)cout<<a[i]<<' ';
   //cout<<endl;
   for(int i=1;i<=s;i++){
    if(a[i]==r){
        cnt=i;
        break;
    }
   }
   //cout<<cnt<<endl;
   int modd=cnt%n,shang=(cnt-modd)/n;
   if(modd==0){
    if(shang%2==0){
        //cout<<n<<' '<<1;
        cout<<shang<<' '<<1;
        return 0;
    }
    else {
        cout<<shang<<' '<<n;
        return 0;
    }
   }
   else {
    if(shang%2==0){
        cout<<shang+1<<' '<<modd;
        return 0;
    }
    else {
        cout<<shang+1<<' '<<n-modd+1;
        return 0;
    }
   }
    return 0;
}
