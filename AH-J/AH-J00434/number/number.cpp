#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            cnt++;
        }
    }
    sort(s.begin(),s.end());
    for(int i=cnt-1;i>=0;i--){
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
