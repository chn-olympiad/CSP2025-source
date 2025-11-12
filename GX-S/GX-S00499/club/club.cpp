#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001],b[1001];
int main()
{

freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>m;
    for(int c=1;c<=m;c++){
        for(int z=1;z<=3;z++){
            cin>>a[c][z];
        }
    }
    for(int k=1;k<=m;k++){
        for(int j=1;j<=3;j++){
            for(int flag=1;flag<=3;flag++){
                if(a[k][j]>a[k][flag]){
                    swap(a[k][j],a[k][flag]);
                }
            }
        }
    }
    for(int l=1;l<=m;l++){
        b[i]+=a[l][1];
    }
}
for(int i=0;i<n;i++){
        cout<<b[i]<<endl;
}
return 0;
}
