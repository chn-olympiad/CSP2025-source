#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int a[666],b[666];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        b[i] = i;
    }
    do{
        int bk = 0,cnt = 0;
        for(int i = 1;i <= n; i++){
            if(bk >= a[b[i]]){
                bk++;
            }else{
                if(s[i-1] == '0'){
                    bk++;
                }else{
                    cnt++;
                }
            }
        }
        ans += (cnt >= m);
    }while(next_permutation(b+1,b+1+n));
    cout << ans;
    return 0;
}
