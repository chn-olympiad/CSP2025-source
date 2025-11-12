#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
string s,ch = " ";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int l = s.size();
    for(int i = 0;i < l;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ch += s[i];
        }
    }
    int t = ch.size() - 1;
    int a[t + 5];
    for(int i = 1;i <= t + 5;i++){
        a[i] = 0;
    }
    int nmax = -1;
    for(int i = 1;i <= t;i++){
        int num = ch[i] - '0';
        nmax = max(nmax,num);
        a[i] = num;
    }
    if(nmax = 0){
        cout<<0;
        return 0;
    }
    sort(a + 1,a + t + 1);
    for(int i = t;i >= 1;i--){
        cout<<a[i];
    }
    return 0;
}
//#Shang4Shan3Ruo6Shui4
