#include<bits/stdc++.h>
using namespace std;
string s;
int k[1000010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int t=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t++;
            k[t]=s[i]-'0';
        }
    }
    sort(k+1,k+t+1,cmp);
    for(int i=1;i<=t;i++){
        cout<<k[i];
    }
    cout<<endl;
    return 0;
}
