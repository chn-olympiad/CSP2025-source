#include<bits/stdc++.h>
using namespace std;
//"RP++RP++RP++RP++RP++"
int n,m,a[105];
int main(){
    cin >> n >> m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0),cout.tie(0);
    for(int i=0;i<n*m;i++)cin >> a[i];
    int x=a[0],y=0;
    sort(a,a+n*m);
    for(int i=n*m;i>0;i--){
        if(a[i-1]==x){
            y=n*m-i+1;
            break;
        }
    }
    int cn1=y/n,cn2=0;
    if(y%n==0){
        if(cn1%2==1)cn2=n;
        else cn2=1;
        cn1--;
    }else{
        if(cn1%2==0)cn2=y-n*cn1;
        else cn2=(cn1+1)*n-y+1;
    }
    cout << cn1+1 << " " << cn2;
    return 0;
}
//AC++AC++AC++AC++AC++
