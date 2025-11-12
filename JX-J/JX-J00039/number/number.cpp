#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000010],k;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            k++;
            b[k]=s[i]-'0';
        }
    }
    sort(b+1,b+k+1,cmp);
    for(int i=1;i<=k;i++){
        cout<<b[i];
    }
    return 0;
}
