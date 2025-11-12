#include<bits/stdc++.h>
using namespace std;
int n,a[6000],k;
bool check(int x,int y){
    int c=a[x];
    for(int i=x+1;i<=y;i++){
        c=c^a[i];
    }
    return c==k;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int c=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(check(i,j)){
                cout<<i<<" "<<j<<endl;
                c++;
                i=j+1;
                break;
            }
        }
    }
    cout<<c;
    return 0;
}
