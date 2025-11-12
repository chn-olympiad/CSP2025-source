#include<bits/stdc++.h>
using namespace std;
int cnt;
int num[1000005];
string s;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(num,num+cnt,cmp);
    if(num[0]==0){
        printf("0");
    }
    else {
        for(int i=0;i<cnt;i++){
            printf("%d",num[i]);
        }
    }
    return 0;
}
