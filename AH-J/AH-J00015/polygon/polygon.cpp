#include<bits/stdc++.h>
using namespace std;
int n,b[6005],k;
vector <int> a;
int l,r;
int sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        a.push_back(k);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        b[i+1]=b[i]+a[i];
    }
    for(int i=2;i<n;i++){
        l=0;
        r=1;
        while(l<r&&r<i){
            if(b[r+1]-b[l]>a[i]){
                sum+=i-r;
                l++;
            }else{
                r++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
