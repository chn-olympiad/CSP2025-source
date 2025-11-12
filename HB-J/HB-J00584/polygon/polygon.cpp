#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l1[5001];
    freopen("polygon.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l1[i];
    }
    fclose(stdin);
    sort(l1,l1+n);
    int l=0,r=l+2;int a=0;
    for(;r<=n;r++){
        int sum=0;
        int i;
        while(i<=r){
            i=l,ma=l1[r],sum=0;
            sum+=l1[i];
            i++;
        }
        if(sum>2*ma)a++;
    }

    for(;l<=n-2;l++){
        int sum=0;
        int i;
        while(i<=r){
            i=l,ma=l1[r],sum=0;
            sum+=l1[i];
            i++;
        }
        if(sum>2*ma)a++;
    }
    freopen("polygon.out","w",stdout);
    cout<<a%998;
    fclose(stdout);
}






























