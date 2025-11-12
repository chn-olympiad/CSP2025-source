#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[100100],vis[100100]={0};
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i] == k){
            cnt++;
            vis[i]+=1;
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
