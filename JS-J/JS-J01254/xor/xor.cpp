#include<bits/stdc++.h>
using namespace std;
int f(vector<int> a,int f,int e){
    int r=a[f];
    for(int k=f+1;k<=e;k++){
        r=(r^a[k]);
    }
    return r;
}
int main(){
    freopen("xor5.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,count=0,i=0,t=0;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int k1=0;k1<n;k1++){
        cin>>a[k1];
    }
    while(i<n){
            int t=0;
        for(int e=i;t==0&&e<n;e++){
            for(int k2=i;k2<=e&&t==0;k2++){
                if(f(a,k2,e)==k){
                    i=e;
                    count++;
                    t=1;
                }
            }
        }
        i++;
    }
    cout<<count;
    return 0;
}
