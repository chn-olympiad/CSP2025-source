#include <bits/stdc++.h>
using namespace std;
string s;
int f[100005],m=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int len=s.size();
    for(int i=0; i<len; i++){
        if(s[i]>='0'&&s[i]<='9'){
            int t=s[i]-'0';
            f[++m]=t;
        }
    }sort(f+1,f+1+m,cmp);
    for(int i=1; i<=m; i++){
        cout << f[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
