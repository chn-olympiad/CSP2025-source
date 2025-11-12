#include<bits/stdc++.h>
using namespace std;
int n=0,a1=0,b1=0,c1=0;
int q(int a,int b,int c,int h){
    if(a>=b and a1!=h){
        if(a>=c){
            a1+=1;
            return a;
        }else if(c1!=h){
            c1+=1;
            return c;
        }else{
            b1+=1;
            return b;
        }
    }else{
        if(b>=c and b1!=h){
            b1+=1;
            return b;
        }else if(c1!=h){
            c1+=1;
            return c;
        }else{
            a1+=1;
            return a;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int a[10000]={},b[10000]={},c[10000]={};
        int num=0;
        cin>>n;
        int e[10000]={};
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            e[i]=max(max(a[i],b[i]),max(a[i],c[i]));
        }
        for(int j=1;j<n;j++){
            for(int i=1;i<n;i++){
                if(e[i]<e[i+1]){
                    swap(a[i],a[i+1]);
                    swap(b[i],b[i+1]);
                    swap(c[i],c[i+1]);
                    swap(e[i],e[i+1]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            num+=q(a[i],b[i],c[i],n/2);
        }
        cout<<num<<endl;
        a1=0;
        b1=0;
        c1=0;
    }
    return 0;
}
