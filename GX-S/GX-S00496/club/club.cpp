#include<iostream>
using namespace std;
int t,n,a[100005],b,c,m,bb,cc,aa;
int main(){
    cin>>t;
    for(int p=0;p<t;p++){
        cin>>n;
        a[0]=1e9;
        int aa=0,bb=0,cc=0;
        m=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>bb>>cc;
            aa=a[i-1];
            c=i;
            while(a[c]>aa){
                b=aa;
                c--;
                a[c]=a[c+1];
                a[c+1]=b;
                aa=a[c-1];
            }
        }
        a[0]=0;
        for(int i=1;i<=m;i++){
            a[0]+=a[i];
        }
        cout<<a[0];
    }
    return 0;
}
