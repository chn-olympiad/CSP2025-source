#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[105],rk[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        rk[a[i]]=i;
    }
    int pos=rk[R];
    //cout<<pos<<' ';
    int l=0,r=0;//l:hang r:lie
    if(pos<=n){
        r=1,l=pos;
    }else{
        r=pos/n+((pos%n)>=1?1:0);
        if(r%2==1){
            l=pos%n;
        }else{
            int tmp=pos%n;
            if(tmp==0) l=1;
            else l=n-tmp+1;
        }
    }
    cout<<r<<' '<<l;
    return 0;
}
