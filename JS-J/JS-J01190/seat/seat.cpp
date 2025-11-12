#include <bits/stdc++.h>
using namespace std;
int bubblesort(int length,int a[],int po,int a1,int n,int m){
    for(int i=1;i<=length;i++)
        for(int j=1;j<=length-i;j++)
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
    for(int i=1;i<=length;i++)
        if(a[i]==a1)
            po=i;
    int h=(po-1)/(2*n)*2;
    if(po%(2*n)==0)
        cout<<h+2<<" "<<1;
    else if(po%(2*n)>n)
        cout<<h+2<<" "<<2*n-(po%(2*n))+1;
    else if(po%(2*n)>=1&&po%(2*n)<=n)
        cout<<h+1<<" "<<po%(2*n);
}
int b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=2,m=2,po=1;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
        cin>>b[i];
    int a1=b[1];
    bubblesort(m*n,b,po,b[1],n,m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
