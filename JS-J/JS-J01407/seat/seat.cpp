#include<bits/stdc++.h>
using namespace std;
const int N=110;
int m,n,x,y,cj,pm,a[N];
bool gz(int x,int y){
    if(x>y) return true;
    else return false;
}
void f(){
    int cnt=1;
    for(int i=1;i<=n;){
        for(int j=1;j<=m;){
            if(cnt==pm){
                x=j;
                y=i;
                return;
            }
            if(j%2==1){
                if(i==n) j++;
                else i++;
            }
            else{
                if(i==1) j++;
                else i--;
            }
            cnt++;
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cj=a[1];
    sort(a+1,a+n*m+1,gz);
    for(int i=1;i<=n*m;i++){
        if(a[i]==cj){
            pm=i;
            break;
        }
    }
    f();
    cout<<x<<' '<<y;
    return 0;
}
