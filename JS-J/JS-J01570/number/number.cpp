#include<bits/stdc++.h>
using namespace std;
string a;
int flag[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a;
    int len=a.size();

    for(int i=0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'){
            flag[ a[i]-'0' ]++;
        }
    }
    for(int i=9;i>=0;){
        if(flag[i]){
            cout<<i;
            flag[i]--;
        }
        else if(flag[i]==0){
            i--;
        }
    }
    return 0;
}
