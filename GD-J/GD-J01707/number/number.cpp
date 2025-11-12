#include <bits/stdc++.h>
using namespace std;

string s;
char sz[1000007];
int cnt;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            sz[cnt]=s[i];
            cnt++;    
        }
    }
    sort(sz,sz+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<sz[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

