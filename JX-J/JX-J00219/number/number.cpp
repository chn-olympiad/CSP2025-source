#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int m[1001];
    int j = 0;
    int lenn = s.length();
    for(int i = 0;i < lenn;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int a = s[i] - '0';
            m[j] = a;
            j++;
        }
    }
    sort(m,m+j);
    for(int i = j - 1;i >= 0;i--){
        cout<<m[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
