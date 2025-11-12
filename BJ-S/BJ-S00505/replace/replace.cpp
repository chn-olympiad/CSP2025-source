#include<bits/stdc++.h>
using namespace std;
int n, q;
string a[200010], b[200010];
int f(string s, string t, string u, string v){
    //cout<<u<<"*** ";
    int cnt = 0;
    int lens = s.length(), lenu = u.length();
    for(int i = 0; i < lens; i++){
        if(i + lenu > lens) return cnt;
        if(s[i] == u[0]){
            bool flag = true;
            //cout<<"$"<<s[i]<<" "<<u[0]<<"$ ";
            //if(u == "bc") cout<<"! ";
            for(int j = 1; j < lenu; j++){
                //if(u == "bc") cout<<"!! ";
                if(s[i + j] != u[j]){
                    //cout<<s[i + j]<<" "<<u[j]<<" ";
                    flag = false;
                    break;
                }
                //if(u == "bc") cout<<"!! ";
            }
            if(!flag) continue;
            string s1 = s;
            for(int j = 0; j < lenu; j++){
                s1[i + j] = v[j];
            }
            //if(u == "bc") cout<<"@"<<s1<<"@ ";
            if(s1 == t){
                cnt++;
                //cout<<"!"<<u<<"! ";
            }
        }
    }
    return cnt;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>b[i];
    }
    while(q--){
        string x, y;
        cin>>x>>y;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += f(x, y, a[i], b[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
