#include<iostream>
using namespace std;
int a[1<<20];
int d[200000];
int main(){
    for(int i=0;i<1<<20;i++)a[i]=-1;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    int xo=k,x;
    for(int i=0;i<n;i++){
        cin>>x;
        xo^=x;
        if(a[xo]==-1)d[i]=xo==0;
        else d[i]=d[a[xo]]+1;
        d[i]=max(d[i-1],d[i]);
        a[xo^k]=i;
    }
    cout<<d[n-1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
