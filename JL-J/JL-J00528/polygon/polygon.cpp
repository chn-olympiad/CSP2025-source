#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int g=3;g<=n;g++){
        for(int aa=0;aa<n;aa++){
            for(int i=0;i<n-g+1;i++){
                for(int j=i+1;i++){
                    if(aa+i>j&&j+i>aa&&j+aa>i)
                        sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
