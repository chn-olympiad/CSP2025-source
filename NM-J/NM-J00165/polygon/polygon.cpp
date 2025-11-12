#include <bits/stdc++.h>

using namespace std;

int a[5005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,l=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                l = max(a[i],a[j]);
                l = max(l,a[k]);
                if(a[i]+a[j]+a[k]>2*l){
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
