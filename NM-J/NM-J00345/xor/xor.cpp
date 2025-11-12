#include<bits/stdc++.h>
using namespace std;
int n,k,a[500500],c,b,d[10001000][3],dc;


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            b=a[i];
            if(a[i]==k){
                c++;
                d[dc][1]=i;
                d[dc][2]=i;
                dc++;
                continue;
            }
        for(int j=i+1;j<=n;j++){
            b=b^a[j];
            if(b==k){
                c++;
                d[dc][1]=i;
                d[dc][2]=j;
                dc++;
                break;
            }
        }
    }
    for(int i=0;i<dc;i++){
        for(int j=i+1;j<dc;j++){
            if(d[i][1]<=d[j][1]&&d[i][2]>=d[j][2]){
                c--;
            }
        }
    }
    cout<<c;
    return 0;
}
