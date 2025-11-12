#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],n;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[(int)s[i]-(int)'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
