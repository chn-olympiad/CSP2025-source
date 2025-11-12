#include<bits/stdc++.h>
using namespace std;
string a;
long long c[10000005];
char li[10] = {'0','1','2','3','4','5','6','7','8','9'};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    long long num=0;
    for(int i=0;i<a.size();i++){
        char b;
        b = a[i];
        if(b-'0'>=0&&b-'0'<=9){
            c[num] = b-'0';
            num = num+1;
        }
    }
    string ans;
    sort(c,c+num);
    for(int i = num-1;i>=0;i--){
        ans = ans+li[c[i]];
    }
    cout<<ans<<endl;
    return 0;
}
