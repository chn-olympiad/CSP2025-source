#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool maxnum(int x,int y){
    return x>y;
}

int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,x,y,t;
    cin>>n>>m;
    int a[100001];
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int s=a[1];
    sort(a+1,a+n*m+1,maxnum);
    for(int i=1;i<=n*m;i++){
        if(s==a[i])
            s=i;
    }
    t=s%n;
    s=s/n+1;
    if(m==1&&n==1){
        cout<<"1 1";
        return 0;
    }
    cout<<s<<" "<<t;



    return 0;
}
