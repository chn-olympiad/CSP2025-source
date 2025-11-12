#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    int z=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    int w=0;
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==z){
            w=i;
            break;
        }
    }

    int c=0,r=0;

    if((w%n)!=0){
        c=(w/n)+1;
        if(c%2==1){
            r=w-(n*(c-1));
        }else{
            r=n-(w-(n*(c-1)))+1;
        }
    }else{
        c=w/n;
        if((w/n)%2==1){
            r=n;
        }else{
            r=1;
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
