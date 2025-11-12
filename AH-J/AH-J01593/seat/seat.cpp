#include<bits/stdc++.h>
using namespace std;
int n,m,seat[102];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>seat[i];
    }
    int R=seat[1],no;
    sort(seat+1,seat+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(seat[i]==R) no=i;
    }
    int cut=1,c,r;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                if(cut==no){
                    c=i;
                    r=j;
                    cout<<c<<" "<<r;
                    return 0;
                }
                cut++;
            }
        }
        else{
            for(int j=1;j<=m;j++){
                if(cut==no){
                    c=i;
                    r=j;
                    cout<<c<<" "<<r;
                    return 0;
                }
                cut++;
            }
        }
    }
    return 0;
}
