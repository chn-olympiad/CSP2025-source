#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1],b[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n*m,cmp);
    int pos;
    for(int i=1;i<=n*m;i++){
        if(b[i]==a[1]){
            pos=i;
        }
    }
    int x=0,y=0;
    x+=pos/(2*n)*2;
    pos%=(2*n);
    //cout<<pos<<" "<<n<<"\n";
    if(pos==0){
        y=1;
        cout<<x<<" "<<y;
        return 0;
    }
    if(pos<=n){
        x++;
        y+=pos;
    }
    if(pos>n){
        x++;
        x++;
        y+=(n-(pos-1-n));
    }
    cout<<x<<" "<<y;
    return 0;
}
