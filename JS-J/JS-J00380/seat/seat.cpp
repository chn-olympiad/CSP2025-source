#include<bits/stdc++.h>
using namespace std;
int a[109];
void sort(int len){
    for(int i=1;i<=len;i++){
        for(int j=i+1;j<=len;j++){
            if(a[j]>a[i]) swap(a[j],a[i]);
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,len,cnt=0,i=0,j=1;
    cin>>n>>m;
    len=n*m;
    for(int i=1;i<=len;i++) cin>>a[i];
    r=a[1],sort(len);
    while(cnt<len){
        while(i+1<=n){
            cnt++,i++;
            if(a[cnt]==r){
                cout<<j<<" "<<i;
                return 0;
            }
        }
        j++,cnt++;
        if(a[cnt]==r){
            cout<<j<<" "<<i;
            return 0;
        }
        while(i-1>=1){
            cnt++,i--;
            if(a[cnt]==r){
                cout<<j<<" "<<i;
                return 0;
            }
        }
        j++,cnt++;
        if(a[cnt]==r){
            cout<<j<<" "<<i;
            return 0;
        }
    }
    return 0;
}
