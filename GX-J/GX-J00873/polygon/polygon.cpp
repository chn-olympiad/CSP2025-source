#include<bits/stdc++.h>
using namespace std;
int a[100000],n,sum;
bool cmp(int a,int b){
    if(a<b)
        return false;
    return true;
}
int power2(int a){
    int r=1;
    for(int i=0;i<a;i++){
        r=r*2;
    }
    return r;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(i<j+k){
                    sum=sum+power2(n-k-1)-1;
                }
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
