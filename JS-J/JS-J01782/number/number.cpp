#include<bits/stdc++.h>
#define N 20
using namespace std;
string s;
int cnt[N];
bool f=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(isdigit(s[i])){
            int x=int(s[i]-'0');
            cnt[x]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(cnt[i]>0){
            if(i!=0) f=1;
            if(!f&&i==0){
                cout<<0;
                return 0;
            }
            for(int j=1;j<=cnt[i];j++) cout<<i;
        }
    }
    return 0;
}

