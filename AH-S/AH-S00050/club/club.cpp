#include<bits/stdc++.h>

using namespace std;

int t, n, a[100005][5];
int A[100005];
long long ans;
int cnt[5];

void dfs(int idx, long long sum){
    //cout << idx << " " << sum << endl;
    //for(int i=1; i<=3; i++){
     //   cout << cnt[i] << " ";
    //}
    //cout << endl;
    if(idx >= n){
        ans = max(ans, sum);
        return ;
    }

    for(int i=1; i<=3; i++){
        if(cnt[i] < n/2){
            cnt[i]++;
            dfs(idx+1, sum+a[idx+1][i]);
            cnt[i]--;
        }
    }
    return ;
}

void dfsB(int idx, long long sum){
    if(idx >= n){
        ans = max(ans, sum);
        return ;
    }

   for(int i=1; i<=2; i++){
       if(cnt[i] < n/2){
           cnt[i]++;
           dfs(idx+1, sum+a[idx+1][i]);
           cnt[i]--;
       }
   }
   return ;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        bool flagA = true;
        bool flagB = true;
        for(int i=1; i<=n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][2]!=0 || a[i][3]!=0){
                flagA = false;
            }
            if(a[i][3] != 0){
                flagB = false;
            }
        }
        if(n == 2){
            long long ma[10]={ a[1][1]+a[2][2],
                         a[1][1]+a[2][3],
                         a[1][2]+a[2][1],
                         a[1][2]+a[2][3],
                         a[1][3]+a[2][1],
                         a[1][3]+a[2][2] };
            for(int i=0; i<=5; i++){
                ans = max(ans, ma[i]);
            }
        }else if(flagA){
            for(int i=1; i<=n; i++){
                A[i] = a[i][1];
            }
            sort(A+1, A+n+1);
            for(int i=n; i>=n/2+1; i--){
                ans += A[i];
            }
        }else if(flagB){
            dfsB(0, 0);
        }else{
            dfs(0, 0);
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
