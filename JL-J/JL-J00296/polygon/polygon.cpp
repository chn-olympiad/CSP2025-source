#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0,tot=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        for(int j=0;j<i;j++){
            int k=0,l=0;

            sum+=a[k];
            l=max(l,a[k]);
            if(sum>2*l){
                tot++;
            }
            else{
                k++;
            }
            k++;

        }
    }

    cout<<tot-1;

    return 0;
}
