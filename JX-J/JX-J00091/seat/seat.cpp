#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1001]={};
long long bj[101]={};
long long ans;
long long h,l;
long long s=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //freopen("seat.in","r",stdin);
    //freopen("seat.p","w",stdout);
    cin>>n;
    cin>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
        bj[a[i]]=1;
    }
    ans=a[1];
    for(long long i=100;i>=ans;i--){
        if(bj[i]==1){
            s++;
        }
    }
 //   cout<<s<<endl;
    if(s%n==0){
        if(s%n==0 and s/n%2==1){
            cout<<s/n<<" "<<n;
          //  cout<<1;
        }
        else if(s%n==0 and s/n%2==0){
            cout<<s/n<<" "<<1;
           // cout<<2;
        }
    }
    else{
        if(s/n%2==1){
            cout<<s/n+1<<" "<<n-s%n+1;
            //cout<<3;
        }
        else{
            cout<<s/n+1<<" "<<s%n;
           // cout<<4;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
