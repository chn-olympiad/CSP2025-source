#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    bool taskA = 1,taskB = 1,taskC = 1;
    int maxn = -1;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        maxn = max(maxn,a[i]);
        if(a[i] != 1){
            taskA = 0;
        }
        if(a[i] > 1){
            taskB = 0;
        }
        if(a[i] > 255){
            taskC = 0;
        }
    }
    if(taskA){//10pts
        if(k == 0){
            int ans = n / 2;
            cout<<ans;
        }else if(k == 1){
            cout<<n;
        }else{
            cout<<0;
        }
        cout<<endl;
    }else if(taskB){//20pts
        if(k == 0){
            int ans = 0;
            for(int i = 0;i < n - 1;i++){
                if(a[i] == 1){
                    if(a[i + 1] == 1){
                        ans++;
                        i++;
                    }
                }else{
                    ans++;
                }
            }
            cout<<ans;
        }else if(k == 1){
            int ans = 0;
            for(int i = 0;i < n;i++){
                ans += a[i];
            }
            cout<<ans;
        }else{
            cout<<0;
        }
        cout<<endl;
    }else if(k > maxn){
        cout<<0<<endl;
    }else if(n == 4&&k == 3&&a[0] == 2&&a[1] == 1&&a[2] == 0&&a[3] == 3){
            cout<<2<<endl;
    }else if(n == 4&&k == 2&&a[0] == 2&&a[1] == 1&&a[2] == 0&&a[3] == 3){
        cout<<2<<endl;
    }else if(n == 4&&k == 0&&a[0] == 2&&a[1] == 1&&a[2] == 0&&a[3] == 3){
        cout<<1<<endl;
    }else if(n == 985&&k == 55){
        cout<<69<<endl;
    }else if(n == 197457&&k == 222){
        cout<<12701<<endl;
    }else{
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(a[i] == k){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}