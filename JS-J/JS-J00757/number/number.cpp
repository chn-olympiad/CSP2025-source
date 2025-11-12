#include<bits/stdc++.h>
using namespace std;
int snum[1000001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int un = 0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            un++;
            snum[un] = s[i]-'0';
        }
    }
    sort(snum+1,snum+1+un,cmp);
    if(snum[1]==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=un;i++){
        cout<<snum[i];
    }
    return 0;
}
