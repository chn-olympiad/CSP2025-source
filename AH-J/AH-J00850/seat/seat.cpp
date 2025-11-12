#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[1005],cnt=1,l,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
            if(a[i]>a[1]) cnt++;
    }
    l+=cnt/n;
    if(cnt%n) l++;
    if(l&1) h=cnt%n;
    else h=n-cnt%n+1;
    if(h==0) h=n;
    cout<<l<<" "<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
