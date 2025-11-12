#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s[1000001];
    cin>>s[1000001];
    int q[1000001];
    for(int i=0;i<=1000001;i++){
        if(s[i]>='1'&&s[i]<='9'){
             q[i]=s[i];
        }
    }cout<<q[1000001];
    return 0;
}
