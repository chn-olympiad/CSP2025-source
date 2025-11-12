#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s;
    cin>>n>>m;
    for(int i=0;i<n*m;i++) cin>>a[i];
    s=a[0];
    sort(a,a+n*m);
    int mc=1,h=1,l=1;
    bool f=1,f1=0;
    for(int i=n*m-1;i>=0;i--){
        if(a[i]==s) break;
        if(((l==1&&i!=n*m-1)||l==n)&&f1==0){
            h++;
            f=!f;
            f1=1;
        }
        else if(f==1){
            l++;
            f1=0;
        }
        else{
           l--;
           f1=0;
        }
    }
    cout<<h<<" "<<l;
    return 0;
}
