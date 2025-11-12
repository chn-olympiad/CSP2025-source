#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a[110];
int main()
{
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdin);
    cin>>n>>m;
    int b[n][m];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
       if(a[i]<a[i+1]){
        a[i]=a[i+1];
        a[i+1]=a[i];
       }
        for(int j=1;j<=n;j++){
        for(int z=1;z<=m;z++)
           a[i]=b[j][z];
     }
     if(a[i]>m){
        m+=1;
        n=i;
        a[i]=b[m][n];

     }

       cout<<1<<2;
    }

fclose(stdin);
fclose(stdout);
    return 0;
}
