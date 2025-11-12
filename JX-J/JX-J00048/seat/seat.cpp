#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e2+10;
int n,m,a[N],r;
bool cmp(int A,int B){
    return A>B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    int i=1,j=1,id=1;
    bool flag=false;
    while(a[id]!=r){
        if(!flag){
            if(i==n) j++,flag=true;
            else i++;
        }
        else{
            if(i==1) j++,flag=false;
            else i--;
        }
        id++;
    }
    cout<<j<<' '<<i<<'\n';
    return 0;
}