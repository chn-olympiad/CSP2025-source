#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[10000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=3;i<=n;i++){
        int he=0,max=-1;
        for(int j=1;j<=i;j++){
            sort(a+1,a+n+1,cmp);
            max=a[i];
            if(j!=1){
                he+=a[j];
            }

        }
        if(he>max){
            cnt++;
            cnt=cnt%988;
        }
    }
    cout<<cnt;
    return 0;
}
