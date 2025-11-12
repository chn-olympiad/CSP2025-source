#include<bits/stdc++.h>
using namespace std;
const int maxn  = 1e6+10;
string s;
int v[maxn],cnt=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            v[cnt] = s[i]-'0';
            cnt++;
        }
    }
    sort(v+1,v+1+cnt,cmp);
    for (int i=1;i<cnt;i++){
        cout<<v[i];
    }
    cout<<endl;
    return 0;

}
