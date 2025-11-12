#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000],b[10000];
int cnm(int x,int y){

}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cnm(i,j);
        }
    }
    return 0;
}
