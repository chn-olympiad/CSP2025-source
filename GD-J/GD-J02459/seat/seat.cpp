#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i <= n*m;i++){
        cin >> a[i];
    }
    int f=a[1];
   // cout << f << endl;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i <= n*m;i++){
        //cout << i << ' ' << a[i] << endl;
        if(a[i]==f){
          //  cout << endl;
            //cout << a[i] <<' ' << f << endl;
            f=i;
            break;
        }
    }
    //cout << f << endl;
    int c=0,r=0;
    c=f/n;
    f%=n;
    if(f>0){
        c++;
    }
    if(f==0){
        if(c%2==0){
            r=1;
        }
        else{
            r=n;
        }
    }
    else{
        if(c%2==0){
            r=n-f+1;
        }
        else{
            r=f;
        }
    }
    cout << c << ' ' << r;
    return 0;
}
