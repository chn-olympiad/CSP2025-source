#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int h;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    h=a[1];
    sort(a+1,a+n*m+1);
    int i=1,j=1,cnt=1;
    bool f=0;
    while(1){
        if(a[n*m-cnt+1]==h){
            cout<<j<<" "<<i;
            return 0;
        }
        else if(!f){
            i++;
            cnt++;
            if(i==n+1){
                i--;
                j++;
                f=1;
            }
        }
        else{
            i--;
            cnt++;
            if(i==0){
                i++;
                j++;
                f=0;
            }
        }
    }
    return 0;
}
