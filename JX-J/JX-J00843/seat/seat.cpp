#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[1005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>b[1];
    int sum=b[1];
    for(int i=2;i<=n*m;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(b[i]==sum){
            sum=i;
            break;
        }
    }
    int num;
    if(sum%n==0){
        cout<<sum/n<<" ";
        num=sum/n;
    }else{
        cout<<sum/n+1<<" ";
        num=sum/n+1;
    }
    if(num%2==0){
        if(sum%n!=0){
            cout<<n-(sum%n)+1;
        }else{
            cout<<1;
        }
    }else{
        if(sum%n!=0){
            cout<<(sum%n);
        }else{
            cout<<n;
        }
    }
    return 0;
}
