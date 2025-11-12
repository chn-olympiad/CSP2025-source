#include<bits/stdc++.h>
using namespace std;
int n,m,r,rd;
int a[11][11];
int b[105];
bool cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int q=n*m;
    cin>>r;
    for(int i=1;i<=q-1;i++){
        cin>>b[i];
    }
    sort(b+1,b+q,cmp);
    for(int i=1;i<=q-1;i++){
        if(r<b[i]&&r>b[i+1]){
            rd=i+1;
        }
    }
    if(rd%n==0&&(rd/n)%2==1){
        cout<<rd/n<<" "<<n;
        return 0;
    }
    if(rd%n==0&&(rd/n)%2==0){
        cout<<rd/n<<" "<<"1";
        return 0;
    }
    if(rd%n!=0&&(rd/n)%2==0){
        cout<<rd/n+1<<" "<<rd%n;
        return 0;
    }
    if(rd%n!=0&&(rd/n)%2==1){
        cout<<rd/n+1<<" "<<n-(rd%n)+1;
        return 0;
    }
    return 0;
}
