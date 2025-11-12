#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,a[N],m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1],k;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            k=i;
            break;
        }
    }
    int i=1,j=1,cnt=1;
    while(cnt<k){
        cnt++;
        if(j%2==1) {
            if(i==n) j++;
            else i++;
        }
        else {
            if(i==1) j++;
            else i--;
        }
    }
    cout<<j<<" "<<i;
    return 0;
}
