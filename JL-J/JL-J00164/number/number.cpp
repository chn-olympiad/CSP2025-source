#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> num;

    int cnt=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num.push_back(int(s[i]-48));
            cnt++;
        }
    }
    int num2[cnt];
    for(int i=0;i<cnt;i++){
        num2[i]=num[i];
    }
    sort(num2,num2+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<num2[i];
    }
    return 0;
}
