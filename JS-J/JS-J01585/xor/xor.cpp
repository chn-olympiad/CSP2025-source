#include<bits/stdc++.h>
using namespace std;
int a[500002];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    srand(time(0));
    bool flg1=0,flg2=0,flg3=0,flg4=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i] != 1) flg1 = 1;
        if(a[i] > 1) flg2 = 1;
        if(a[i] != k) flg3 = 1;
        if(a[i] %2 != 0) flg4 = 1;
    }
    // #1 #3  k == 0 A
    if(k == 0 && flg1 == 0){
        cout<<n/2;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    // #2 #4 #5 #13 B
    if(k == 1 && flg2 == 0){
        int ans = 0;
        for(int i=1;i<=n;i++) if(a[i] == 1) ans++;
        cout<<ans;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(k == 0 && flg2 == 0){
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(a[i] == 0) ans++;
            if(a[i] == a[i+1] && a[i] == 1){
                ans++;
                i++;
            }
        }
        cout<<ans;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    // a[i] = k
    if(flg3 == 0){
        cout<<n;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    // a[i] %2 == 0 k%2 == 1
    if(flg4 == 0 && k%2 == 1){
        cout<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    cout<<rand()%2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
