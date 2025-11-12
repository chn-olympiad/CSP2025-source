#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int xo[N];
int n,k,cnt = 0;
int ans = 0;
bool vis[N];
void clean(){
    for(int i = 0;i<n-1;i++){
        if(xo[i] != k && vis[i] == false){
            if(vis[i-1] == true && vis[i+1] == true){
                vis[i] = true;
            }
        }
    }
}
int bg(int x){
    for(int i = x;i<n;i++){
        if(vis[i] == false){
            return i;
        }
    }
    return -1;
}
int ed(int x){
    for(int i = x+1;i<n;i++){
        if(vis[i] == true){
            return i-1;
        }
    }
    return n-1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> xo[i];
        if(xo[i] == k){
            vis[i] = true;
            cnt++;
        }
    }



    int step = 0,j = 0;
    int start = 0;
    bool flag = 0;
    while(step < n){
        clean();
        int l = bg(step),r = ed(l);
        if(l == -1 || r == -1)break;
        for(int i = l;i<=r;i++){
            start = i,j = i,ans = 0;
            flag = 0;
            while(j <= r){
                ans = (ans ^ xo[j]);
                j++;
                if(ans == k){
                    cnt++;
                    for(int m = start;m<j;m++){
                        vis[m] = true;
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
        }
        for(int i = l;i<=r;i++)vis[i] = true;
        step = r;
    }
    cout << cnt;
    return 0;
}
