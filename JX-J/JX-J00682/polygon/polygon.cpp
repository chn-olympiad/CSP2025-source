#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int _count=0;
    int sum=0;
    int _max=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=_max){
            _max=a[i];
        }
    }
    for(int r=1;r<=n-2;r++){
        for(int l=3;l<=n;l++){
            for(int i=r;i<=l;i++){
                sum+=a[i];
            }
            if(sum>_max){
                _count++;
            }
            sum=0;
        }
    }
    cout<<_count;
}
