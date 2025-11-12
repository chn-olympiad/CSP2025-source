#include<bits/stdc++.h>
using namespace std;
int sum[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9') sum[s[i]-'0']++;
    }
    int f=0;
    for(int i=9;i>=0;i--){
        if(sum[i]>0){
            if(i==0&&f==0){
                cout<<0;
                return 0;
            }
            for(int j=1;j<=sum[i];j++) cout<<i;
            f=1;
        }
    }
    return 0;
}
