#include <bits/stdc++.h>
using namespace std;
int point[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n ,m,r;
    cin>>n>>m;
    int h=0,l=1;
    for(int i = 1;i<=n*m;i++){
        cin>>point[i];
    }
    r=point[1];
    sort(point,point+n*m+1);
    for(int i = n*m;i>=1;i--){
        if(l%2==1) h++;
        if(l%2==0) h--;

        if((h>n&&l%2==1)){
            l++;
            h--;
        }else if(h<1&&l%2==0){
            l++;
            h++;
        }
        if(point[i]==r) cout<<l<<" "<<h;


    }
    return 0;
}
