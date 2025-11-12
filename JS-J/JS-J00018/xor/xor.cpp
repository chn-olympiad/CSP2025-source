#include <bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int n,k;
int cnt;
int fuck;
int q;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
   for(int i=1;i<=n;i++){
        cin>>a[i];
   }
   if(a[1]==k) {
    b[1]=1;
    fuck=-1;
    q=2;
   }else{
    b[1]=0;
    fuck=a[1];
    q=1;

   }
   for(int i=2;i<=n;i++){
    if(a[i]==k){
        b[i]=b[i-1]+1;
        fuck=-1;
        q=i+1;
    }else{
        if(fuck==-1){
            fuck=a[i];
            b[i]=b[i-1];
        }else{
            int c=fuck^a[i];
        if(c==k){
            b[i]=b[i-1]+1;
            fuck=-1;
            q=i+1;
        }else{
        int x=a[i];
        bool f=1;
        for(int j=i-1;j>=q;j--){
            x=x^a[j];
            if(x==k){
                b[i]=b[i-1]+1;
                fuck=-1;
                q=i+1;
                f=0;
            }
        }
        if(f==1){
            b[i]=b[i-1];
            fuck=fuck^a[i];
        }
        }
    }
    }
   }
   cout<<b[n]<<endl;
    return 0;
}
