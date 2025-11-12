#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    vector <int> b(n,0);
    vector <int> c(n,0);
    for(int i = 0;i < n;i++){
        cin>>b[i];
        c[i] = i+1;
    }
    int ans = 0,fail = 0,people = 0;
    do{
        for(int i = 0;i < a.length();i++){
            if(b[c[i]-1] <= fail){fail++;continue;}
            if(a[i] == '0'){
                fail++;
            }
            else{
                people++;
            }
        }
        if(people >= m){
            ans++;
            ans %= 998244353;
        }
        fail = 0;
        people = 0;
    }
    while(next_permutation(c.begin(),c.end()));
    cout<<ans<<endl;
    return 0;
}
