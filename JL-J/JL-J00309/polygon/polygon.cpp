#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n[100],a,e;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    int z=3;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(n[j]<n[j+1]){
                swap(n[j],n[j+1]);
            }
        }
    }
    int m,g,h;

        for(int j=z;j<a;j++){
                h++;
                n[h]=h;
            for(int d=j;d<a;d++){
                    g++;
                    n[g]=g;
                for(int c=d;c<a;c++){
                    m++;
                    n[m]=m;
                    if(h+g+m>2*h){
                        e++;
                    }
                }
            }
        }
    cout<<e;
    return 0;
}
