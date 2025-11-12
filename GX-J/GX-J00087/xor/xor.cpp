#include<bits/stdc++.h>
using namespace std;
int n,m,b=0,sum=0;
long long a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=b;j<=i;j++){
            int num=0;
            for(int k=j;k<=i;k++){
                num^=a[k];
            }
            if(num==m){
                sum++;
                b=i+1;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
