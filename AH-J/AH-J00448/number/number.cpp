#include<bits/stdc++.h>
using namespace std;
int num[1000005],in=1;
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
            num[in++]=s[i]-'0';
        }
    }
    sort(num+1,num+in,cmp);
    if(num[1]==0)printf("0");
    else{
        for(int i=1;i<in;i++){
            printf("%d",num[i]);
        }
    }
    return 0;
}
