#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],n1=1,m1=1,x;
bool cmp(int q,int h){
    return q>h;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            x=i;
            break;
        }
    }
    for(int i=1;i<=x;i++){
        if(i==x){
            break;
        }
        if(i%n==0){
            m1++;
        }
        else{
            if(m1%2==1){
                n1++;
            }
            else{
                n1--;
            }
        }
    }
    cout<<m1<<" "<<n1;
    return 0;
}
