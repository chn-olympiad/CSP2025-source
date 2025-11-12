#include <bits/stdc++.h>

using namespace std;

int lst[500000];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, ans=0;
    bool fa=1, fb=1;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>lst[i];
        if(lst[i]!=1){
            fa=0;
        }
        if(lst[i]>1){
            fb=0;
        }
    }
    if(fa){
        cout<<n/2;
        return 0;
    }
    if(fb){
        if(k==0){
            for(int i=0; i<n; i++){
                if(lst[i]==0){
                    ans++;
                }else{
                    if(lst[i+1]==1){
                        ans++;
                        i++;
                    }
                }
            }
        }else{
            for(int i=0; i<n; i++){
                if(lst[i]==1){
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
