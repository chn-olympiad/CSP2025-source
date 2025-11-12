#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool  b(int a,int b){
    if(a>b) return true;
    else return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=m*n;
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    int r=a[0];
    sort(a,a+s,b);
    int x;
    for(int i=0;i<s;i++){
        if(a[i]==r) x=i;
    }
    x++;
    int y;
    double z=double(x)/double(n);
    if(z>int(z)){
        y=int(z)+1;
    }else{
        y=int(z);
    }
    cout<<y<<' ';
    bool flag=(y%2==1);
    //cout<<endl<<flag<<endl;
    int c=1;
    for(int i=(y-1)*n+1;i<=n;i++){
        if(a[i-1]==r){
            break;
        }
        c++;
    }
    if(flag){
        cout<<c;
    }else{
        cout<<n+1-c;
    }
    return 0;
}
