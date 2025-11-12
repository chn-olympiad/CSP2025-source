#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n;
    long long m=0;
    cin>>n;
    int a[n],b[n+1]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i-1];
    }
    for(int i=2;i<n;i++){
        int s=2;
        while(s<=i){
            int k=s,st=0;
            while(st<=i-s){
                int qu=b[st+s]-b[st];
                while(qu<=a[i]){
                    qu=qu-a[k-1]+a[k];
                    k++;
                    }
                if(k<i)m=m+i-k+1;
                st++;
            }
            s++;
        }
    }
    cout<<m;
    return 0;
}
