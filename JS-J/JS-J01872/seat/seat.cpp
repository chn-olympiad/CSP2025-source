#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],tmp,mark;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    tmp=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;;i++){
        if(a[i]==tmp){
            mark=i;
            break;
        }
    }
    if(mark%n==0){
        if(mark/n%2==1)cout<<mark/n<<" "<<n;
        else cout<<mark/n<<" "<<1;
    }else if(((mark/n)+1)%2==1){
        cout<<(mark/n)+1<<" "<<mark%n;
    }else{
        cout<<(mark/n)+1<<" "<<n-mark%n+1;
    }
    return 0;
}
