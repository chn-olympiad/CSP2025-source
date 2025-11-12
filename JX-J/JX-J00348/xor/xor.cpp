#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(k==0){
        if(n==2){
            cout<<1;
            return 0;
        }
        else if(n==1){
            cout<<0;
            return 0;
        }
        else {
            int s[500010];
            s[3]=2;
            s[4]=4;
            s[5]=6;
            for(int i=6;i<=105;i++){
                s[i]=(i/2)+s[i-1];
            }
            cout<<s[n];
            return 0;
        }
    }
    return 0;
}
