#include<bits/stdc++.h>
using namespace std;
int n,m,a[121];
bool cmp(int s1,int s2){
    return s1>s2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m,i=1,j=1,x=0;
    for(i=1;i<=k;i++)
        cin>>a[i];
    int r=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)
        if(a[i]==r){
            x=i;
            break;
        }
    cout<<x<<endl;
    if(x<n)
        cout<<1<<" "<<x<<endl;
    else{
        int y=ceil((float)x/n);
        if(y%2==0)
            x=n*m+1-x;
        else
            x-=n*(y-1);
        cout<<y<<" "<<x<<endl;
    }
    return 0;
}
