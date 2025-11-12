#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int hang,lie;
    int a[105];
    cin>>hang>>lie;
    for(int i=1;i<=hang*lie;i++){
        cin>>a[i];
    }
    int tmp=a[1];
    sort(a+1,a+hang*lie+1,cmp);
    int c,r;
    for(int i=1;i<=hang*lie;i++){
        if(a[i]==tmp){
            int x=i;
            if(x%hang!=0) c=x/hang+1;
            else c=x/hang;
            if(c%2==1){
                if(x%hang!=0)r=x%hang;
                else r=hang;
            }
            else{
                if(x%hang!=0)r=hang-(x%hang)+1;
                else r=1;
            }
            break;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
