#include<bits/stdc++.h>
#define ld long long
#define llf long double
using namespace std;
string s;
int a[10]={};
bool flag=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        if(flag==0&&i==0){
            printf("0");
            return 0;
        }
        while(a[i]--){
            flag=1;
            printf("%d",i);
        }
    }
    return 0;
}
