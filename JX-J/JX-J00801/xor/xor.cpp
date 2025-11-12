#include<bits/stdc++.h>
using namespace std;
long long n, k, a[1100000], wb;
bool flag[1100000];
void uu(int l, int r){
    for(int i=l;i<=r;i++) flag[i]=true;
    return;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(flag[i]==0 && flag[j]==0){
                long long num=a[i];
                for(int z=i+1;z<=j;z++){
                    num=num^a[z];
                }
                if(num==k) {wb++;uu(i, j);}
            }
        }
    }
    cout<<wb;
    return 0;
}
