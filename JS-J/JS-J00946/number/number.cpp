#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn=1e6+10;
int f[maxn];
int a[maxn];long long oioi=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto c:s){
        if('0'<=c&&c<='9'){
            f[c-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(f[i]>0){
            f[i]--;
            a[oioi]=i;oioi++;
        }
    }
    for(int i=1;i<oioi;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
