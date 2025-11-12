#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int l,r;
    int flag;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n<=1&&m<=1){
        cout<<1<<" "<<1;
        return 0;
    }
    flag=a[1];
    //cout<<flag<<endl;
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        //cout<<a[i];
        b[n*m-i+1]=a[i];
        //cout<<b[i]<<" ";
    }
    //cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<' '<<b[4];
    /*cout<<b[3];*/
    for(int i=1;i<=n*m;i++){
        if(flag==b[i]){
           flag=i;
           break;
        }
        //else cout<<i<<" ";
    }
    //cout<<endl<<flag<<endl;
    l=flag/n;
    r=flag%n;
    //cout<<l<<" "<<r<<endl;
    //cout<<l<<endl;
    if(r==0){
        //cout<<"r=0"<<" "<<endl;
        cout<<l<<" ";
    }
    else {
        //cout<<"r!=0"<<" "<<endl;
        cout<<l+1<<" ";
        r=r-1;
    }
    if(l%2==1)cout<<r+2;
    else if(l%2==0)cout<<n-r-1;
    return 0;
}
