#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string ch;
long long ans[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>ch;
    int str=ch.size();
    for(long long i=0;i<str;i++){
        if(ch[i]>='0'&&ch[i]<='9'){
            ans[int(ch[i]-'0')]+=1;
        }
    }
    for(long long i=N;i>=0;i--){
        if(ans[i]!=0){
            for(int j=0;j<ans[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
