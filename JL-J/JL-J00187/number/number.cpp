#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            //cout << s[i] << " ";
            a[cnt]+=s[i]-'0';
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int i=0;i<cnt/2;i++){
        swap(a[i],a[cnt-i-1]);
    }
    for(int i=0;i<cnt;i++){
        cout << a[i];
    }
    //cout << cnt << endl;
    return 0;
}
