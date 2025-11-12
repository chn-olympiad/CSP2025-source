#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    vector<long long>b(10,0);
    for(auto c:a){
        if('0'<=c && c<='9'){
            b[c-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(long long j=0;j<b[i];j++){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
