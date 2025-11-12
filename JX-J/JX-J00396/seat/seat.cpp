#include<bits/stdc++.h>
using namespace std;
int n,c=1,r=1,a[101],m,s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    cin>>a[i];
    s=a[1];
    for(int i=1;i<n*m;i++){
        for(int j=n*m;j>i;j--){
            if(a[j]>a[j-1]){
                a[0]=a[j];
                a[j]=a[j-1];
                a[j-1]=a[0];
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==s)
            break;
        if(c%2!=0)
            r++;
        if(c%2==0)
            r--;
        if(c%2!=0&&r>n){
            c++;
            r--;
        }
        if(c%2==0&&r<1){
            c++;
            r++;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
