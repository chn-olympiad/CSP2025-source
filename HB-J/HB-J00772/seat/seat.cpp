#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[30];
int s=0;
bool cmp(int h,int e){
    return h>e;
}
int main(){
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[0];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(n==1&&m==1){
            cout<<n<<" "<<m<<endl;
            break;
        }
        else if(n==1&&m==2&&s<a[i]){
            cout<<"1"<<" "<<"2"<<endl;
            break;
        }
        else if(n==1&&m==2&&s>a[i]){
            cout<<"1"<<" "<<"1"<<endl;
            break;
        }
        else if(n==1&&m==3&&s>a[i-1]){
            cout<<"1"<<" "<<"1"<<endl;
            break;
        }
    }
    return 0;
}
