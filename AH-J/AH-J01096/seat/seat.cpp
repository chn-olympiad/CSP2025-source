#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int l=1,r=1;
int d=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=m*n;i++){
        cin>>a[i];
   }
   int t=a[1];
   for(int i=1;i<n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[i]<a[j])swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            cout<<r<<" "<<l;
            return 0;
        }
        if(r%2){
            if(l==n)r++;
            else l++;
        }
        else{
            if(l==1)r++;
            else l--;
        }
    }
}
