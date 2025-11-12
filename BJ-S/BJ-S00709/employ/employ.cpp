#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int mod=998244353;
int C[510][510];
int a[510];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=mod;
        }
    }
    string s;
    cin >> s;
    s=" "+s;
    /*
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            flag=0;
            break;
        }
    }
    */
    int maxm=n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==0){
            maxm--;
        }
    }
    if(maxm<m){
        cout << 0;
        return 0;
    }
    vector<int> va;
    for(int i=1;i<=n;i++){
        va.emplace_back(i);
    }
    int ans=0;
    do{
        int tmpcnt=0,failcnt=0;
        for(int i=0;i<n;i++){
            if(failcnt>=a[va[i]]||s[i+1]=='0'){
                failcnt++;
            }
            else{
                tmpcnt++;
            }
        }
        ans+=(tmpcnt>=m?1:0);
        /*
        if(tmpcnt>=m){
            for(int i=0;i<n;i++){
                cout << va[i] << " ";
            }
            cout << endl;
        }
        */
        ans=(ans>=mod?ans-mod:ans);
    }while(next_permutation(va.begin(),va.end()));
    cout << ans;
    return 0;
}
