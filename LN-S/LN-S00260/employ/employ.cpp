#include<bits/stdc++.h>
using namespace std; 

const int mod = 998244353;
int n, m; 
string str; 
int s[550], c[550]; 
int cf[550]; //cha fen; 
int q[550], vis[550]; 
long long ans = 0; 

bool check(){
    memset(cf, 0, sizeof(cf)); 
    int take = 0; 
    for(int i = 1; i <= n; i++){
        if(s[i] == 0) cf[i+1]++; 
        else{
            int g = 0; 
            for(int j = 1; j <= i; j++) g += cf[j]; 
            if(g < c[q[i]]) take++; 
            else cf[i+1]++; 
        }
    }
    if(take >= m) return true;
    else return false; 
}

void find_order(int pos){
    if(pos == n+1){
        if(check())ans = (ans+1)%mod;
        return; 
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue; 
        q[pos] = i; 
        vis[i] = 1; 
        find_order(pos+1);  
        vis[i] = 0; 
    }
    return; 
}

int main(){
    freopen("employ.in", "r", stdin); 
    freopen("employ.out", "w", stdout); 
    scanf("%d%d", &n, &m); 
    cin >> str; 
    for(int i = 1; i <= n; i++) s[i] = str[i-1]-'0';  
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);  
    find_order(1); 
//    cout << pow(2, 18) << endl;
    printf("%lld", ans); 
    return 0; 
}