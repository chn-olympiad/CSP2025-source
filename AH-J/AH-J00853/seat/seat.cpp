#include<bits/stdc++.h>;
using namespace std;
int  n,m;
int a[106];
int cmp1(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
    }
    int x=0;
    int r=a[1];
    sort(a+1,a+1+n*m,cmp1);
    for(int i=1;i<=n*m;i++){
            if(a[i]==r){
                x=i;
                break;
            }
    }
    if(x<=n){
        cout<<1<<" "<<x;
        return 0;
    }
    int yu=x%n;//duo
    if(yu>0){
        if((x/n+1)%2==1){
            cout<<x/n+1<<" "<<yu;
        }else{
            if(yu==1){
                cout<<x/n+1<<" "<<m;
            }else{
                cout<<x/n+1<<" "<<n-yu;
            }
        }
    }else if(yu==0){
        cout<<x/n<<" "<<m;
    }
    return 0;
}
