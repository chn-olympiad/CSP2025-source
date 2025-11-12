#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string mp;
    cin>>mp;
    int num[1000010] = {};
    for(int i = 0;i<mp.size();i++){
        char cnt = mp[i];
        if('0'<=cnt && cnt<='9'){
            num[0]++;
            num[num[0]] = cnt-'0';
        }
    }
    sort(num+1,num+num[0]+1);
    for(int i = num[0];i>=1;i--){
        printf("%d",num[i]);
    }
}
