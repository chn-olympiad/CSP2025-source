#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001];
int main(){
    freopen("polygon.in",'r',stdin);
    freopen("polygon.out",'w',stdout);
    int n,s=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=a[i]+b[i-1];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(b[j]-b[i]>a[j]*2){
                s++;
            }
        }
    }
    cout<<s*3;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
