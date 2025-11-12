#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int r;
int h,l;
int mingci;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n*m;i++){
                cin>>a[i];
        }
        r=a[1];
        int w=n*m;
        sort(a,a+w);
        for(int i=w;i>=1;i--){
               if(a[i]==r){
                    mingci=w-i;
               break;
        }
}
        int sum=2*n;
        int x=mingci/sum;
        int y=mingci%sum;
        if(n>=y)cout<<x*2+1<<" "<<y;
        if(y>n)cout<<x*2+2<<" "<<sum-y+1;
    return 0;
}
